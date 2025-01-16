function [t,x]=rk4(x0,u,tf,K,Char_stat)
nt=length(u);n=length(x0);h=tf/nt;x=zeros(nt,n);
tmp=zeros(n,1);xtmp=x0;x(1,:)=x0';t=0;
dx1=zeros(n,1);dx2=dx1;dx3=dx1;dx4=dx1;
h_2=h/2; h_6=h/6; h_26=2*h_6;
for i=1:nt
 dx1=rhs(xtmp,u(i),K,Char_stat);
 tmp=xtmp+h_2*dx1;t=t+h_2;
 dx2=rhs(tmp,u(i),K,Char_stat);
 tmp=xtmp+h_2*dx2;
 dx3=rhs(tmp,u(i),K,Char_stat);
 tmp=xtmp+h*dx3;t=t+h_2;
 dx4=rhs(tmp,u(i),K,Char_stat);
 xtmp=xtmp+h_6*(dx1+dx4)+h_26*(dx2+dx3);
 x(i,:)=xtmp';
end
t=linspace(0,tf,nt)';