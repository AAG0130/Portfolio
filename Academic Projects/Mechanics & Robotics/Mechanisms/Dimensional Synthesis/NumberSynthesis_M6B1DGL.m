% Universidad EAFIT
% program : Mechanical Engineering
% subject : Mechanisms
% author  : R.M. Martinod - rmartino@eafit.edu.co
% date    : March - 2022
% main    : given a mechanism configuration,
%           to calculate a set of mecanism alternatives
%           based on the number syntesis theory,  
% this script finds just a configuration according the parameters
%---------------------------------------
% clear workspace
clc, clear all, format compact
%---------------------------------------
% mechanisms configuration
G = 1;        % number of DOF
N = 6;        % number of bars
M = G + 3;    % movility 
m = N/2;      % max. order of bars & joints
%---------------------------------------
% lineal eq. system: B = X*A
%   [n3  p2  p3]
A = [ 1  0   0 ;   % eq.4
      1  1   0 ;   % eq.5 
     -3  3   2];   % eq.6
%---------------------------------------
% iteration process
for(n2 = 4:N)
   % constrains
   B = [N-n2;    % eq.4
        2;       % eq.5
        2*n2];   % eq.6
   %¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
   % solving the lineal eq. system: X = A/B
   %  X = A^(-1)*B;     % this expression can solve the lineal eq. system
   %  X = inv(A)*B;     % this expression solves the system too
   X = linsolve(A,B);   % it solves the linear system AX = B using one of these methods:
                     % when A is square, linsolve uses LU factorization with partial pivoting.
                     % for all other cases, linsolve uses QR factorization with column pivoting.
                     % linsolve warns if A is ill conditioned (for square matrices) or rank deficient (for rectangular matrices)
   %¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
   fprintf('\n(%d,%d,%d,%d)',n2,round(X(1)),round(X(2)),round(X(3)))
end