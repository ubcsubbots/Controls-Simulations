% This script derives the time derivative of the frame conversion
% martrix J using symbolic functions of time

% phi, theta, psi are all symbolic functions of t (time)
syms phi_t(t) theta_t(t) psi_t(t) phi theta psi phi_dot theta_dot psi_dot

% calculate J matrix using symbols
cphi = cos(phi_t);
sphi = sin(phi_t);
cth  = cos(theta_t);
sth  = sin(theta_t);
cpsi = cos(psi_t);
spsi = sin(psi_t);
 
J1 = [...
   cpsi*cth  -spsi*cphi+cpsi*sth*sphi  spsi*sphi+cpsi*cphi*sth
   spsi*cth  cpsi*cphi+sphi*sth*spsi   -cpsi*sphi+sth*spsi*cphi
   -sth      cth*sphi                  cth*cphi ];
  
J2 = [...
      1  sphi*sth/cth  cphi*sth/cth;
      0  cphi          -sphi;
      0  sphi/cth      cphi/cth ];
 
J = [ J1  zeros(3,3);
      zeros(3,3) J2 ];

% symbolic differentiation of J with respect to t
J_dot_sym = diff(J,t);

% syms to substitute
old = [ phi_t(t), ...
        theta_t(t), ...
        psi_t(t), ...
        diff(phi_t(t),t) ...
        diff(theta_t(t),t) ...
        diff(psi_t(t), t) ];

% substitution values
new = [ phi, ...
        theta, ...
        psi, ...
        phi_dot, ...
        theta_dot, ...
        psi_dot ];
    
% Calculate J_dot with substituted values
J_dot = subs(J_dot_sym, old, new);

J_dot;