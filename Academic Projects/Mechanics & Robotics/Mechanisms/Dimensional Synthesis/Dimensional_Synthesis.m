theta1=deg2rad(0);
theta2=deg2rad(20);
theta3=deg2rad(5);
psi1=deg2rad(30);
psi2=deg2rad(110);
psi3=deg2rad(130);

A = [cos(psi1) -cos(theta1) 1;
     cos(psi2) -cos(theta2) 1;
     cos(psi3) -cos(theta3) 1];
B = [cos(theta1-psi1) cos(theta2-psi2) cos(theta3-psi3)]';
k=inv(A)*B;
disp(k)

k1=k(1);
k2=k(2);
k3=k(3);

%Tomar tierra como d=10
d=10;
b=(d/k1);
c=(d/k2);
a=sqrt(b^2+c^2+d^2-2*b*c*k3);
disp([a b c d])
