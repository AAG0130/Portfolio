%%secante: se ingresa el valor inicial (x0),segundo valor de x(x1), la tolerancia del error (Tol) y el màximo nùmero de iteraciones (niter)%%

x0=input('ingrese primer valor: ');
x1=input('ingrese segundo valor: ');
tol=input('ingrese valor de tolerancia: ');
niter=input('ingrese maximo de iteraciones: ');
[xn,fx,E] = secante(x0,x1,tol,niter);

function[xn,fx,E] = secante(x0,x1,tol,niter)
    syms x
    %funcion a evaluar%
    
    f=sin(x-9.4609)-(exp(x-2.4)-x^(2))/(2.5);
    
    %__________________________%
    
    c = 0;
    fx(c+1) = eval(subs(f,x0));
    fx0 = fx(c+1);
    E(c+1) = tol+1;
    E(c+2) = tol+1;
    error = E(c+1);
    xn(c+1) = x0;
    xn(c+2) = x1;
    N(c+1) = c;
    if fx0==0
        s=x0;
        n=c;
        fprintf('%f es raiz de f(x) \n',x0)
    else
        fx(c+2) = eval(subs(f,x1));
        fx1 = fx(c+2);
        den = fx1 - fx0;
        c = c+1;
        N(c+1) = c;
    end
    
    while error>tol && den~=0 && fx1~=0 && c<niter
        xn(c+2) = x1-(fx1*(x1-x0))/den;
        %calculo del error absoluto%
        
        %E(c+2) = abs(xn(c+2)-xn(c+1));
             
        %calculo de error relativo%
        
        E(c+2) = abs((xn(c+2)-xn(c+1))/xn(c+2));
        
        error = E(c+2);
        x0=x1;
        x1=xn(c+2);
        fx(c+2) = eval(subs(f,x1));
        fx0=fx(c+1);
        fx1=fx(c+2);
        den = fx1 - fx0;
        c = c+1;
        N(c+1) = c;
    end
    if fx1==0
        s=x1;
        n=c;
        fprintf('%f es raiz de f(x) \n',x1)
    elseif error<tol
        s=x1;
        n=c;
        fprintf('%f es una aproximación de una raiz de f(x) con una tolerancia= %f \n',x1,tol)
    elseif den==0
        disp('hay una posible raiz multiple')
    else
        s=x1;
        n=c;
        fprintf('Fracasó en %f iteraciones \n',niter)
    end
     T=table(N',xn',fx',E','variableNames',{'n','xn','fx','E'});
        disp(T)
        plot(xn,fx,'r')
        grid on
        hold on
        
    end    
      
    
        
        
        
            
            
        