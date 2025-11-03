clear
clc
close all
format long

r2=3;
r3=6;
r4=2.5;
theta4=deg2rad(90);
theta1=deg2rad(0);
%theta2=deg2rad(0); %% Degree of freedom
q=[8.4;-2.7]; %%Semilla [r1(d); theta3]

counter=0;
for theta2=0:0.1:2*pi
    counter=counter+1;
    tol=100;
    iter=0;

    while tol>1e-7 && iter<100
        iter=iter+1;
        F=[-(q(1))*cos(theta1)+r2*cos(theta2)-r3*cos(q(2))-r4*cos(theta4);
           -(q(1))*sin(theta1)+r2*sin(theta2)-r3*sin(q(2))-r4*sin(theta4)];
        J=[-cos(theta1), r3*sin(q(2)); 
           -sin(theta1), -r3*cos(q(2))];
        qi=-inv(J)*F+q;
        tol=norm(F);
        q=qi;
    end
    %q(1)=mod(q(1),2*pi);
    %q(2)=mod(q(2),2*pi);
    P(:,counter)=q;
    if iter>=100
        disp('no hubo convergencia')
        return
    end
end

x=0:0.1:2*pi;
plot(x,x,"r");
hold on
plot(x,P(1,:),"g")
plot(x,P(2,:),"b")