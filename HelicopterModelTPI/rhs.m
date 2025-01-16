function dx=rhs(x,u,K,Char_stat)
H = polyval(Char_stat, x);
dx=K*(u-H);
end