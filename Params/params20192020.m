% This script is run when this MATLAB project starts up

% Add Library to the path
path = mfilename('fullpath');
[currdir,~,~] = fileparts(path);
[rootdir,~,~] = fileparts(currdir);
addpath(fullfile(rootdir,'Library'));

% BLOCK PARAMETERS
v = 0.2;                      % Desired averaged speed used by the trajectory planner (m/s)
thrust_upper_limit = 10;      % The upper bound on desired thrust/torque produced by controller (N)
thrust_lower_limit = -10;     % The lower bound on desired thrust/torque produced by controller (N) 
eta_0 = [0;0;0;0;0;0];        % Startpoint pose of the trajectory
eta_ref = [6;2;1;0;0;3.14/2]; % Endpoint pose of the trajectory

% CONSTANTS
const.rho_water = 998.0;  % water density          (Kg/m^2)
const.g = 9.81;           % gravitational constant (m/s^2)

% AUV MODEL PARAMETERS
%
% Parameters are stored in a single struct so it is easy to pass them into
% a Simulink MATLAB function block

params.m = 18.7; %14.405;                     % mass of auv        (Kg)
params.V = 0.0188;                            % volume of auv      (m^3)
params.W = params.m*const.g;                  % auv weight         (Kg)
params.B = const.rho_water*const.g*params.V;  % auv buoyancy force (N)

params.xg = 0;          % x coordinate centre of gravity (m)
params.yg = 0;          % y coordinate centre of gravity (m)
params.zg = 0;          % z coordinate centre of buoyancy (m)
params.xb = 0;          % x coordinate centre of buoyancy (m)
params.yb = 0;          % y coordinate centre of buoyancy (m)
params.zb = 0.1;        % z coordinate centre of gravity (m)
params.Ixx = 13.4;        % inertia around x-axis (Kg*m^2)
params.Iyy = 15.7;        % inertia around y-axis (Kg*m^2)
params.Izz = 8.98;        % inertia around z-axis (Kg*m^2)

params.Xu = 0.525;         % x linear drag parameter (Ns/m)
params.Yv = 0;         % y linear drag parameter (Ns/m)
params.Zw = 7.25;         % z linear drag parameter (Ns/m)
params.Kp = 0;         % roll linear drag parameter (Ns/m)
params.Kq = 0;         % pitch linear drag parameter (Ns/m)
params.Nr = 0;         % yaw linear drag parameter (Ns/m)

params.Xuu = 85.625;   % x quadratic drag parameter (Ns^2/m^2)
params.Yvv = 0;        % y quadratic drag parameter (Ns^2/m^2)
params.Zww = 215;      % z quadratic drag parameter (Ns^2/m^2)
params.Kpp = 0;        % roll quadratic drag parameter (Ns^2/m^2)
params.Kqq = 0;        % pitch quadratic drag parameter (Ns^2/m^2)
params.Nrr = 0;        % yaw quadratic drag parameter  (Ns^2/m^2)

params.alpha = 45;  % angle of each horizontal thruster off 
                    % of the longitudinal axis (Deg)
                             
params.L1x = 10.833*cosd(52.704); % x and y length of thruster 1 
params.L1y = 10.833*sind(52.704); % (front right) from the COM (in)

params.L2x = 11.238*cosd(54.261); % x and y length of thruster 1 
params.L2y = 11.238*sind(54.261); % (front left) from the COM (in)

params.L3x = 11.466*cosd(48.73); % x and y length of thruster 1 
params.L3y = 11.466*sind(48.73); % (back right) from the COM (in)

params.L4x = 11.85*cosd(50.34); % x and y length of thruster 1 
params.L4y = 11.85*sind(50.34); % (back left) from the COM (in)

params.L5x = 8.744; % x length of thruster 5 (top right) from the COM (in)

params.L6x = 8.239; % x length of thruster 6 (top left) from the COM (in)
