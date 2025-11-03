clc
clear
close all

x=input("Insertar las x: ");
y=input("Insertar las y: ");
d=input("Insertar el grado del polinomio: ");

xpol1=x(1):0.001:x(2);
xpol2=x(2):0.001:x(3);

[Tabla1] = Spline(x,y,d)

p3=Tabla1(1,1)*xpol1+Tabla1(1,2);
p4=Tabla1(2,1)*xpol2+Tabla1(2,2);

plot(x,y,'r*',xpol1,p3,'b-',xpol2,p4,'k-')
Tabla1(2,1)*10+Tabla1(2,2)