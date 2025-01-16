load dane

u = u.signals.values;
y = y.signals.values;
tf=15; %Czas trwania pomiarów tf=t(end)

f_celu= @(K) cel(K,u,tf,y, Char_stat);
K_min = fminsearch(f_celu, 5000);

[t,x]=rk4(0,u,tf,K_min,Char_stat);
figure;
hold on
plot(t,x);
plot(t,y);
grid on;
legend('Model','Rzeczywiste')