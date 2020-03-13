function [thruster_signals, thrust, tau_actual, I_sum] = thrust_allocator_test(tau, params)
%#codegen

% [thruster_signals, thrust, tau_actual, I_sum] = thrust_allocator(tau, params) returns the
% actual thrust the thrusters can produce, and a vector of PWM signals to 
% send to the thruster array on board the UBC Subbots AUV given a desired 
% input thrust vector tau. 

% Load params into local vars
alpha = params.alpha;
L1x = params.L1x;
L1y = params.L1y;
L2x = params.L1x;
L2y = params.L1y;
L3x = params.L1x;
L3y = params.L1y;
L4x = params.L1x;
L4y = params.L1y;
L5x = params.L5x;
L6x = params.L6x;

% We want to solve for the actual thrust forces each thruster will provide
% to reach the total forces and torques given by tau. The equation we have
% is Au = tau, where u contains the x and y thrust components of each thruster in
% the horizontal plane and the total thrust for the vertical thrusters. We
% have u = [T1x, T1y, T2x, T2y, T3x, T3y, T4x, T4y, T5, T6]. 

% A is the allocating matrix 
A = [ -1, 0, -1, 0, 1,  0, 1, 0, 0, 0; ... % x axis force contributions
       0, -1, 0, 1, 0, -1, 0, 1, 0, 0; ... % y axis force contributions
       0,  0, 0, 0, 0,  0, 0, 0, 1, 1; ... % z axis force contributions (should they be negative ??)
       0,   0,    0,    0,    0,    0,   0,   0,   -L5x, L6x; ... % x axis torque contributions
       0,   0,    0,    0,    0,    0,   0,   0,    0,   0; ...   % y axis torque contributions
       -L1x, -L1y, L2x, L2y, L3x, L3y, -L4x, -L4y,  0,   0; ...   % z axis torque contributions 
       1/cosd(alpha), -1/sind(alpha), 0, 0, 0, 0, 0, 0, 0, 0; ... % thruster 1 angle restrictions
       0, 0, 1/cosd(alpha), -1/sind(alpha), 0, 0, 0, 0, 0, 0; ... % thruster 2 angle restrictions
       0, 0, 0, 0, 1/cosd(alpha), -1/sind(alpha), 0, 0, 0, 0; ... % thruster 3 angle restrictions
       0, 0, 0, 0, 0, 0, 1/cosd(alpha), -1/sind(alpha), 0, 0 ];   % thruster 4 angle restrictions

% Append a zero for each thruster to account for the equations which
% restrict the thruster forces based on the angle alpha
tau_prime = [tau;0;0;0;0];

% Ignore any y torque
tau_prime(5) = 0;

% We cannot solve directly for a solution since A is not ivnvertible, so we
% take A's pseudoinverse to solve for the least squares solution of u
u = pinv(A)*tau_prime;

T1x = u(1); 
T1y = u(2);
T2x = u(3);
T2y = u(4);
T3x = u(5); 
T3y = u(6);
T4x = u(7);
T4y = u(8);
T5  = u(9);
T6  = u(10);

% Create the vector of absolute thrust for each thruster
thrust = [  sign(T1x)*sqrt(T1x^2 + T1y^2); ...
            sign(T2x)*sqrt(T2x^2 + T2y^2); ...
            sign(T3x)*sqrt(T3x^2 + T3y^2); ...
            sign(T4x)*sqrt(T4x^2 + T4y^2); ...
            T5; ...
            T6];
        
% Round thrust to 3 decimals
thrust = round(thrust*1000)/1000;

% Helper function for getting PWM signal associted to thrust 
function signal = get_signal(thrust)
%#codegen
if thrust > 0
    signal = -0.1885*thrust^2 + 18.706*thrust + 1539.5;
elseif thrust < 0
    signal = 0.6287*thrust^2 + 31.212*thrust + 1456.9;
else
    signal = 1500;
end
end
    
thruster_signals = zeros(6,1);

thruster_signals(1) = get_signal(thrust(1));
thruster_signals(2) = get_signal(thrust(2));
thruster_signals(3) = get_signal(thrust(3));
thruster_signals(4) = get_signal(thrust(4));
thruster_signals(5) = get_signal(thrust(5));
thruster_signals(6) = get_signal(thrust(6));

% Calculate I_i for i = [1,...6] and make sure that the sum of I_i's < 12
I_sum = 0;
for i=1:6
    pwm_i = thruster_signals(i);
    I_i = 0.00008*pwm_i^2 - 0.2392*pwm_i + 178.75;
    I_sum = I_sum + I_i;
end

if I_sum > 12
    % Uh oh ...
end

% We expect to produce exact input thrust (for now)
tau_actual = tau;

end

% Examples To Test

% No force, should produce all 1500 signals
% tau = [0;0;0;0;0;0] 

% Only z force should produce roughly equal > 1500 signals for T5, T6
% tau = [0;0;1;0;0;0] 

% Only -z force should produce roughly equal < 1500 signals for T5, T6
% tau = [0;0;-1;0;0;0] 

% Only x force should produce roughly equal > 1500
% signals for T3, T4, roughly equal < 1500 signals for T1, T2
% tau = [1;0;0;0;0;0] 

% Only -x force should produce roughly equal < 1500
% signals for T3, T4, roughly equal > 1500 signals for T1, T2
% tau = [-1;0;0;0;0;0] 

% Only y force should produce roughly equal > 1500
% signals for T2, T4, roughly equal < 1500 signals for T1, T3
% tau = [0;1;0;0;0;0] 

% Only -y force should produce roughly equal < 1500
% signals for T2, T4, roughly equal > 1500 signals for T1, T3
% tau = [0;-1;0;0;0;0] 

% Only z torque, should produce roughly equal > 1500 signals for T2,T3 and
% roughly equal < 1500 signals for T1,T4
% tau = [0;0;0;0;0;1]

% Only -z torque, should produce roughly equal < 1500 signals for T2,T3 and
% roughly equal > 1500 signals for T1,T4
% tau = [0;0;0;0;0;-1]

% Only x torque, should produce roughly equal < 1500 signal for T5 and
% roughly equal > 1500 signal for T6
% tau = [0;0;0;1;0;0]

% Only -x torque, should produce > 1500 signal for T5 and < 1500 signal for
% T6 where each is roughyl the same distance to 1500
% tau = [0;0;0;-1;0;0]

% Check to make sure our thrust saturation upper/lower limit does not
% break the constraint that I_sum < 12 
% tau = [10;10;10;10;10;10] % Should have I_sum < 12
% tau = [-10;-10;-10;-10;-10;-10] % Should have I_sum < 12

% Run this command for each tau and analyze outputs (params should already
% be in the workbench on project startup)
% [thruster_signals, thrust, tau_actual, I_sum] = thrust_allocator_test(tau, params)

