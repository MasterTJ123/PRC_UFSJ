clc()
clear()

function Y = F(x)
    
    Y = [ (x(1)^2)-(x(2)^2)
          2*x(1)*x(2)-1 ];
    
endfunction

function Z = J(x)

    Z = [ 2*x(1) -2*x(2)
          2*x(2) 2*x(1) ];

endfunction

k = 0;

x(1) = input("Insira o x0(1): ");
x(2) = input("Insira o x0(2): ");  
      
Fx = F(x);

erro = 1;

tolmax = input("Insira a tolerância máxima: ");

it_max = input("Insira a quantidade máxima de iterações: ");

printf("Iteração(k)\t\t\tx(k)\t\t\t\t\tF(x(k))\n");
printf("%d\t\t\tx1=%.8f e x2=%.8f\t\tFx1=%.8f e Fx2=%.8f\n", k, x(1), x(2), Fx(1), Fx(2));

while( (erro > tolmax) & (k < it_max) )
     
    k = k + 1;
    
    dx = inv(J(x))*F(x);
    
    x = x - dx;
    
    Fx = F(x);
    
    erro = max(abs(dx));
    
    printf("%d\t\t\tx1=%.8f e x2=%.8f\t\tFx1=%.8f e Fx2=%.8f\n", k, x(1), x(2), Fx(1), Fx(2));
     
end
