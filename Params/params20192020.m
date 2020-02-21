% This script is run when this MATLAB project starts up
%#codegen

% BLOCK PARAMETERS
v = 2; % Desired averaged speed used by the trajectory planner (m/s)

% Proportional gain matrix
Kp_mat = [ 5, 0, 0, 0, 0, 0; ... % x pos err gain
           0, 3, 0, 0, 0, 0; ... % y pos err gain
           0, 0, 3, 0, 0, 0; ... % z pos err gain
           0, 0, 0, 3, 0, 0; ... % phi rot err gain
           0, 0, 0, 0, 3, 0; ... % theta rot err gain
           0, 0, 0, 0, 0, 3 ];   % psi rot err gain
       
% Derivative gain matrix      
Kd_mat = [ 3, 0, 0, 0, 0, 0; ... % x lin vel err gain
           0, 3, 0, 0, 0, 0; ... % y lin vel err gain
           0, 0, 3, 0, 0, 0; ... % z lin vel err gain
           0, 0, 0, 3, 0, 0; ... % phi ang vel err gain
           0, 0, 0, 0, 3, 0; ... % theta ang ve err gain
           0, 0, 0, 0, 0, 3 ];   % psi ang ves err gain

% CONSTANTS
const.rho_water = 1014.0; % water density          (Kg/m^2)
const.g = 9.81;           % gravitational constant (m/s^2)

% AUV MODEL PARAMETERS
%
% Parameters are stored in a single struct so it is easy to pass them into
% a Simulink MATLAB function block

params.m = 100;                               % mass of auv        (Kg)
params.V = 100;                               % volume of auv      (m^3)
params.W = params.m*const.g;                  % auv weight         (Kg)
params.B = const.rho_water*const.g*params.V;  % auv buoyancy force (N)

params.xg = 0;          % x coordinate centre of gravity (m)
params.yg = 0;          % y coordinate centre of gravity (m)
params.zg = 0;          % z coordinate centre of buoyancy (m)
params.xb = 0;          % x coordinate centre of buoyancy (m)
params.yb = 0;          % y coordinate centre of buoyancy (m)
params.zb = 0;          % z coordinate centre of gravity (m)
params.Ixx = 10;        % inertia around x-axis (Kg*m^2)
params.Iyy = 10;        % inertia around y-axis (Kg*m^2)
params.Izz = 10;        % inertia around z-axis (Kg*m^2)

params.Xu = 10;         % x linear drag parameter (Ns/m)
params.Yv = 10;         % y linear drag parameter (Ns/m)
params.Zw = 10;         % z linear drag parameter (Ns/m)
params.Kp = 10;         % roll linear drag parameter (Ns/m)
params.Kq = 10;         % pitch linear drag parameter (Ns/m)
params.Nr = 10;         % yaw linear drag parameter (Ns/m)

params.Xuu = 10;        % x quadratic drag parameter (Ns^2/m^2)
params.Yvv = 10;        % y quadratic drag parameter (Ns^2/m^2)
params.Zww = 10;        % z quadratic drag parameter (Ns^2/m^2)
params.Kpp = 10;        % roll quadratic drag parameter (Ns^2/m^2)
params.Kqq = 10;        % pitch quadratic drag parameter (Ns^2/m^2)
params.Nrr = 10;        % yaw quadratic drag parameter  (Ns^2/m^2)

params.alpha = 45;  % angle of each horizontal thruster off 
                    % of the longitudinal axis (Deg)
                             
params.L1x = 10.833*cosd(52.704); % x and y length of thruster 1 
params.L1y = 10.833*sind(52.704); % (front right) from the COM (in)

params.L2x = 11.238*cosd(54.261); % x and y length of thruster 1 
params.L2y = 11.238*sind(54.261); % (front left) from the COM (in)

params.L3x = 11.466*cosd(48.73); % x and y length of thruster 1 
params.L3x = 11.466*sind(48.73); % (back right) from the COM (in)

params.L4x = 11.85*cosd(50.34); % x and y length of thruster 1 
params.L4x = 11.85*sind(50.34); % (back left) from the COM (in)

params.L5x = 8.744; % x length of thruster 5 (top right) from the COM (in)

params.L6x = 8.239; % x length of thruster 6 (top left) from the COM (in)
