clc
clear
close all
format long

r2=3;
r3=6;
r4=2.5;
theta4=deg2rad(90);
theta1=deg2rad(0);
theta20=0;
omega20=0; %velocidad inicial
alfa20=0.5; %aceleración inicial

q=[8.4;0;0.43]; %%Semilla [r1(d); theta2; theta3]

%theta2=0; %this is the DoF
counter=0;
ti=0;
ts=0.05;
tf=6;
for t=ti:ts:tf
    counter=counter+1;
    tol=50;
    iter=0;
    while tol>1e-7 && iter<100
        iter=iter+1;
        F=[-(q(1))*cos(theta1)+r2*cos(q(2))+r3*cos(q(3))-r4*cos(theta4);
           -(q(1))*sin(theta1)+r2*sin(q(2))+r3*sin(q(3))-r4*sin(theta4);
           q(2)-theta20-omega20*t-0.5*alfa20*t^2];
    
        J=[-cos(theta1), -r2*sin(q(2)), -r3*sin(q(3)); 
           -sin(theta1), r2*cos(q(2)), r3*cos(q(3));
           0,              1,             0;];
    
        qi=-(J\F)+q;
        tol=norm(F);
        q=qi;
    end
    if iter>99
        disp(strcat('no hubo convergencia, iter=',num2str(counter)))
    end
    %x=floor (q./(2*pi));
    %q(1)=q(1)-x(1)*2*pi;
    %q(2)=q(2)-x(2)*2*pi;
    
    %q(2)=mod(q(2),2*pi);
    %q(3)=mod(q(3),2*pi);
    P(:,counter)=q;

    phi_tp=[0; 0; -omega20-alfa20*t];
    v=-J\phi_tp;
    V(:,counter)=v;

    Jp=[0, -r2*v(2)*cos(q(2)), -r3*v(3)*cos(q(3));
        0, -r2*v(2)*sin(q(2)), -r3*v(3)*sin(q(3));
        0,              0,             0;];
    phi_tpp=[0;0;-alfa20];
    a=-J\(Jp*v+phi_tpp);
    A(:,counter)=a;

end

x=ti:ts:tf;

%grafica posición
figure
plot(x,P(1,:),'r')
hold on
plot(x,P(2,:),'g')
plot(x,P(3,:),'b')
hold off

%grafica velocidad
figure
plot(x,V(1,:),'r')
hold on
plot(x,V(2,:),'g')
plot(x,V(3,:),'b')
hold off

%grafica aceleración
figure
plot(x,A(1,:),'r')
hold on
plot(x,A(2,:),'g')
plot(x,A(3,:),'b')
hold off
