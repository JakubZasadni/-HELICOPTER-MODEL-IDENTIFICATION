load pomiar_oscylacji3.mat
tm = output.time;
ym = output.signals.values;



% k=13;
% tm=data(k,1).t;
% ym=data(k,1).y;
T0=tm(2)-tm(1);
% 
% ym=ym*pi/180;
% gr_gorna = 3000;
% gr_dolna = 200;
% tm=tm(gr_dolna:gr_gorna);
% ym=ym(gr_dolna:gr_gorna);
% tm=tm-tm(1);

x0(1,1)=ym(1);
x0(2,1)=(ym(5)-ym(1))/(5*T0);
a=0.01;c=5;al=0.49;
LB=[-100, -100, 0, 3, 0]';
UB=[100, 100, 0.5, 5, 0.6]';

options=optimset('display','iter');
[xopt,resnorm,residual,exitflag,output,lambda,jacobian]=...
        lsqnonlin('cel_00',[x0;a;c;al],LB,UB,options,tm,ym);
x0=xopt(1:2);a=xopt(3);c=xopt(4);al=xopt(5);

% calkowanie rownan
[t,x] = ode45(@(t,x) rhs_00(t,x,a,c,al),tm,x0);
% porownanie obiekt-model
figure;
plot(t,x(:,1),tm,ym)
% figure;
% plot(tm,ym)