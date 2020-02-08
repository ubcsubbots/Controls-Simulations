% Note that this script is run when this MATLAB project starts up
% Here is where we define parameters which simulink blocks use

% BLOCK PARAMETERS
v = 2; % Desired averaged speed used by the trajectory planner (m/s)

% CONSTANTS
const.rho_water = 1014.0; % water density (Kg/m^2)
const.g = 9.81;           % gravitational constant (m/s^2)

% AUV MODEL PARAMETERS
m = 100;     % mass of auv           (Kg)
Ixx = 10;    % inertia around x-axis (Kg*m^2)
Iyy = 10;    % inertia around y-axis (Kg*m^2)
Izz = 10;    % inertia around z-axis (Kg*m^2)



