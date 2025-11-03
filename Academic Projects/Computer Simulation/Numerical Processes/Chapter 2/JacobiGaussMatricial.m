%MatJacobiSeid: Calcula la solución del sistema
%Ax=b con base en una condición inicial x0,mediante el método de Jacobi o
%de Gauss Seidel (Matricial), depende del método elegido, se elige 0 o 1 en met
%respectivamente
x0=input('ingrese un vector aproximado a la solucion (sin transponer): ');
x0=x0';
A=input('ingrese la matriz: ');
b=input('ingrese el vector de terminos independientes (sin transponer): ');
b=b';
Tol=input('ingrese la tolerancia: ');
niter=input('ingrese numero maximo de iteraciones: ');
met=input('ingrese el # del tipo de metodo siendo: Jacobi=0 ; Gauss Seidel=1: ');
[E,s,T,N,x1] = MatJacobiSeid(x0,A,b,Tol,niter,met);
function [E,s,T,N,x1] = MatJacobiSeid(x0,A,b,Tol,niter,met)
    c=0;
    N(c+1)=c;
    error=Tol+1;
    D=diag(diag(A));
    L=-tril(A,-1);
    U=-triu(A,+1);
    while error>Tol && c<niter
        if met==0
            T=inv(D)*(L+U);
            C=inv(D)*b;
            x1(c+2,:)=T*x0+C;
        end
        if met==1
            T=inv(D-L)*(U);
            C=inv(D-L)*b;
            x1(c+2,:)=T*x0+C;
        end
        E(c+1)=norm(x1-x0,'inf');
        error=E(c+1);
        x0=x1;
        c=c+1;
        N(c+1)=c;
    end
    if error < Tol
        s(:,c+1)=x0;
        n=c;
        fprintf('es una aproximación de la solución del sistema con una tolerancia= %f',Tol)
    else 
        s(:,c+1)=x0;
        n=c;
        fprintf('Fracasó en %f iteraciones',niter) 
    end
    p=0:1:c
    
    fprintf(', el vector:\n');
    disp(s);
    fprintf('los valores de error fueron:\n');
    disp(E');
    fprintf('La matriz T es:\n');
    disp(T);
    RES=max(abs(eig(T)));
    fprintf('El radio espectral de la matriz T es %f \n',RES);
    TT=table(p,s,E);
    disp(TT)

end