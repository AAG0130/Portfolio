clear
clc
format long
met = input("Ingrese el metodo de interpolacion que desea utilizar. 1 para Newton | 2 para Lagrange | 3 para Spline");
if met == 1
    x = input("Ingrese los valores de X: ");
    y = input("Ingrese los valores de Y: ");
    [Tabla] = Newtonint(x,y)
        coef = (diag(Tabla,1))
    [pol] = Newtonor(x,coef)
    disp("El orden de los coeficientes es decendente x^n, x^n-1, ... x^1, x^0")   
elseif met == 2
    x = input("Ingrese los valores de X: ");
    y = input("Ingrese los valores de Y: ");
    [pol] = Lagrange(x,y)
    disp("El orden de los coeficientes es decendente x^n, x^n-1, ... x^1, x^0")
elseif met == 3
    x = input("Ingrese los valores de X: ");
    y = input("Ingrese los valores de Y: ");
    d = input("Ingrese el grado de los polinomios de interpolacion 1 para polinomios lineales 2 para polinomios cuadraticos 3 para polinomios cubicos");
    [Tabla] = Spline(x,y,d)
end
syms x
FUN=pol(1)*x^(length(x)-1)+pol(2)*x^(length(x)-2)+pol(3)*x^(length(x)-3)+pol(4)+x^(length(x)-4)+pol(5);
i=x(1)-5:1:x(length(x))+5;
plot(x,eval(subs(x,FUN)),'r')
