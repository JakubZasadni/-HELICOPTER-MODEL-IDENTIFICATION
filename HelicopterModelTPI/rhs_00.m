function dx=rhs_00(t,x,a,c,al)
dx=zeros(2,1);
dx(1)=x(2);
dx(2)=-a*x(2)-c*sin(x(1)+al);
end