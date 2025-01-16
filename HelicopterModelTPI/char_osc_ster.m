% Parametr kp
u = square_wave.signals.values;
ym = Pitch_angle_osc.signals.values;
tm = Pitch_angle_osc.time;
x0 = [0;0;0];

u = square_wave.signals(1).values;
ym = Pitch_angle_osc.signals(1).values;
tm = Pitch_angle_osc.time;
x0 = [0;0;0];

k=12; ym = ym(k:end,:); tm = tm(k:end,1); u = u(k:end,1);
T0=tm(2)-tm(1);

n0=1; n1=length(tm); tm=tm(n0:n1); ym=ym(n0:n1,:); tm=tm-tm(1); u=u(n0:n1);
x0(1,1)=ym(1,1); x0(2,1)=(ym(5,1)-ym(1,1))/(5*T0); x0(3,1)=ym(1,2);

b=0*0.0107388; d=4.5646;
LB=[-100 -1000 -20000 -10 -30]';UB=[100 1000 20000 10 500]';
options=optimset('display','iter');

[xopt,resnorm,residual,exitflag,output,lambda,jacobian]=...
lsqnonlin('cel_01',[x0;b;d],LB,UB,options,u,tm,ym);

x0=xopt(1:3);b=xopt(4);d=xopt(5);
[t,x]=rk4_01(x0,u,tm(end),b,d);
t = (0:0.01:t)';
figure;plot(t,x(:,1),tm,ym(:,1));grid on; legend("Model","Rzeczywiste")