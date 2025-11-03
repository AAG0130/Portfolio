clc
clear
close all

x=input("Insertar las x: ");
y=input("Insertar las y: ");
d=input("Insertar el grado del polinomio: ");

[Tabla] = Spline(x,y,d);

xpol1=x(1):0.001:x(2);
xpol2=x(2):0.001:x(3);

p1=Tabla(1,1)*xpol1.^3+Tabla(1,2)*xpol1.^2+Tabla(1,3)*xpol1+Tabla(1,4);
p2=Tabla(2,1)*xpol2.^3+Tabla(2,2)*xpol2.^2+Tabla(2,3)*xpol2+Tabla(2,4);

plot(x,y,'r*',xpol1,p1,'b-',xpol2,p2,'k-')
Tabla(2,1)*10.^3+Tabla(2,2)*10.^2+Tabla(2,3)*10+Tabla(2,4)