function q=cel(K,u,tf,y, Char_stat)
[~,x]=rk4(0,u,tf,K,Char_stat);
e=x-y;q=e'*e/length(e);
end