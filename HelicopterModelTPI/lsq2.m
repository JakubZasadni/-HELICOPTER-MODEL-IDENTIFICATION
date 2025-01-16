clear;close all
% Identyfikacja b i d - pelny model
load pitch3.mat
load sterowanie3.mat


k=55;
%tm=y2.time(k,1).t;
%ym=[data_04_silnik(k,1).y
%data(k,1).y1];
% tm=output.time(k:end);
% ym=output.values(k:end);
tm=output.time(k:end);
ym=output.signals.values(k:end);
T0=tm(2)-tm(1);
%ym(:,1)=ym(:,1)*pi/180;
u=input.signals.values(k:end);
% plot(tm,ym,tm,u)
n0=1;
n1=length(tm);
tm=tm(n0:n1);
ym=ym(n0:n1,:);
tm=tm-tm(1);
u=u(n0:n1);
x0(1,1)=ym(1,1);

x0(2,1)=(ym(5,1)-ym(1,1))/(5*T0); % predkosc
x0(3,1)=0; %
b=15;
d=4.5646;
xopt=[x0;b;d];
LB=[-1 -0.3 -2000 0.01 -1]';
UB=[1 1 500 20 1.39]';

%LB=[-10 -300 -50000 -50 -30]';
%UB=[10 300 50000 55 30]';
%
options=optimset('display','iter');
[xopt,resnorm,residual,exitflag,output,lambda,jacobian]=...
lsqnonlin('cel_01',xopt,LB,UB,options,u,tm,ym);
x0=xopt(1:3);
b=xopt(4);
d=xopt(5);
[t,x]=rk4_01(x0,u,tm(end),b,d);
figure;
plot(t,x(:,1),tm,ym(:,1));grid
xlabel('t [s]');
ylabel('\it\phi\rm(t)');
% Error estimates Hessian matrix=J’J
J=full(jacobian);
C=inv(J'*J)*(residual'*residual)/length(residual);
er=3*sqrt(diag(C)) %