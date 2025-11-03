function raicesmultiples
syms x
  f=input('ingrese la funcion: ');
  %f=inline(f);
  fp=diff(f);
  fpp=diff(fp);
  %fp=input('ingrese la dervidad de la funcion: ','s');
  %fp=inline(fp);
  %fpp=input('ingrese la segunda dervidad de la funcion: ','s');
  %fpp=inline(fpp);
  xi=input('escriba el punto de inicio: ');   
  tol=input('Ingrese el error maximo admisible: ');
  n=input('Ingrese el numero maximo de iteraciones permitidas: ');
  %fplot(f,[xi-5,xi+5])
  fx=eval(subs(f,xi));
  fpx=eval(subs(fp,xi));
  fppx=eval(subs(fpp,xi));
  denominador=(fpx^2-fx*fppx);
  i=0;
  error=tol+1;
  er='';
  fprintf('\n n         x        f(x)         fp(x)         fpp(x)         E        er   \n')
  while  i<=n && fx~=0 && error>tol && denominador~=0
        fprintf('%1.0f %10.10f %10.10f %10.10f %10.10f %10.10f %10.10f \n',i,xi,fx,fpx,fppx,error,er)
        x=xi-(fx*fpx)/denominador;
        fx=eval(subs(f,xi));
        fpx=eval(subs(fp,xi));
        fppx=eval(subs(fpp,xi));
        denominador=(fpx^2-fx*fppx);        
        error=abs(x-xi);
        er=abs((x-xi)/x);
        xi=x;
        i=i+1;
  end
    
if fx==0
    fprintf('\n La raíz es: %1.10f \n\n',xi)
  else if error<tol
        fprintf('\n %1.10f es una aproximacion a la raiz con un error maximo de %1.10f \n',xi,tol)
    else
     fprintf('\n El metodo fallo en %0.0f iteraciones \n\n',n)  
       end
end