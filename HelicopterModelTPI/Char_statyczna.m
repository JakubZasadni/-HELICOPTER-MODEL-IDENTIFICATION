PitchCtrl = -1:0.1:1;
U_mierz = [-1.75, -1.61, -1.50, -1.39, -1.28, -1.15, -0.99, -0.80, -0.60,...
    -0.34, 0.00, 0.35, 0.62, 0.84, 1.02, 1.18, 1.32, 1.45, 1.57, 1.65, 1.74];
c=0.52;
n_obr = U_mierz/c*1000;

Char_stat = polyfit(n_obr, PitchCtrl, 3);
poly_RPM2Pitch = polyfit(PitchCtrl, n_obr, 3);

x=linspace(-4000, 4000);
y=polyval(Char_stat, x);
figure;
plot(n_obr, PitchCtrl, '*', x, y)
grid on
ylabel("PitchCtrl")
xlabel("\omega")

x=linspace(-1, 1);
y=polyval(poly_RPM2Pitch, x);
figure;
plot(PitchCtrl, n_obr, '*', x, y)
grid on
xlabel("PitchCtrl")
ylabel("\omega")