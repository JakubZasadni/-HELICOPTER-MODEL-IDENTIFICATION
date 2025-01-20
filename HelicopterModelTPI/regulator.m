%% regulator
K = 7.4055e+03;
a = 0.270635379992858;
c = 4.921249191542748;
al = 0.495440761917189;
b = 0.051492308002346;
d = 0.125788155178429;
[xr, ur]=get_eqpoint(0);% punkt rownowagi
[A,B,C,D]=get_abcd(xr);% linearyzacja

G=[0 0;1 0;0 1];
sg1=5*1e-3;sg2=2;Q=diag([sg1^2 sg2^2]);
sgv1=1e-3;sgv2=2;R=diag([sgv1^2 sgv2^2]);

% LQ controller with integrator
A1=[A zeros(3,1);1 zeros(1,3)];B1=[B;0];
L=lqe(A,G,C,Q,R);
Q1=diag([1 1 0.01 100]);R1=100;
K=lqr(A1,B1,Q1,R1);% LQ with integrator gain
e=eig(A1-B1*K)
