masa=[5, 14, 17, 20, 29, 35, 44, 50, 59, 65, ...
    -5, -14, -20, -29, -35, -44, -50, -59, -65];
masa = sort(masa);

PitchCtrl_sila = [0.19, 0.37, 0.38, 0.41, 0.53, 0.60, 0.69, 0.81, 0.9, ...
    0.97, -0.15, -0.32, -0.4, -0.5, -0.58, -0.71, -0.79, -0.95, -1];
PitchCtrl_sila = sort(PitchCtrl_sila);

g=9.81; %Przyspieszenie [m/s^2]
r1=0.365; %Dlugosc ramienia 1 [m]
r2=0.235; %Dlugosc ramienia 2 [m]
r3=0.25; %Dlugosc ramienia 3 [m]
masa = masa/1000; %Konwersja z gramów na kg

sila = zeros(size(masa));
%Dla ujemnych
sila(1:9) = masa(1:9)*r1*g/r2;
%Dla dodatnich
sila(10:end) = masa(10:end)*r3*g/r2;

rpm = polyval(poly_RPM2Pitch, PitchCtrl_sila);

plot(rpm, sila)
xlabel("RPM")
ylabel("Siła [N]")