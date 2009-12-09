// Funcion Objetivo
min: + A0 + A1 + A2 + A3 + A4 + A5 + A6;

// Points
// {[10.0;0.0] , [20.0;0.0] , [25.0;0.0] , [40.0;0.0] , [50.0;0.0] , [55.0;0.0] , [60.0;0.0]}

// Calculo de las Distancias entre la escuela y las veredas
// Distancia de la escuela a 0
// Distancia en X
Dx0 - ex + 10.0 - 200 Nx0 >= -200;
Dx0 - ex + 10.0 + 200 Nx0 <= 200;
Dx0 - 10.0 + ex + 200 Nx0 >= 0;
Dx0 - 10.0 + ex - 200 Nx0 <= 0;
// Distancia en Y
Dy0 - ey + 0.0 - 200 Ny0 >= -200;
Dy0 - ey + 0.0 + 200 Ny0 <= 200;
Dy0 - 0.0 + ey + 200 Ny0 >= 0;
Dy0 - 0.0 + ey - 200 Ny0 <= 0;
// Distancia Total
Dx0 + Dy0 = D0;

// Distancia de la escuela a 1
// Distancia en X
Dx1 - ex + 20.0 - 200 Nx1 >= -200;
Dx1 - ex + 20.0 + 200 Nx1 <= 200;
Dx1 - 20.0 + ex + 200 Nx1 >= 0;
Dx1 - 20.0 + ex - 200 Nx1 <= 0;
// Distancia en Y
Dy1 - ey + 0.0 - 200 Ny1 >= -200;
Dy1 - ey + 0.0 + 200 Ny1 <= 200;
Dy1 - 0.0 + ey + 200 Ny1 >= 0;
Dy1 - 0.0 + ey - 200 Ny1 <= 0;
// Distancia Total
Dx1 + Dy1 = D1;

// Distancia de la escuela a 2
// Distancia en X
Dx2 - ex + 25.0 - 200 Nx2 >= -200;
Dx2 - ex + 25.0 + 200 Nx2 <= 200;
Dx2 - 25.0 + ex + 200 Nx2 >= 0;
Dx2 - 25.0 + ex - 200 Nx2 <= 0;
// Distancia en Y
Dy2 - ey + 0.0 - 200 Ny2 >= -200;
Dy2 - ey + 0.0 + 200 Ny2 <= 200;
Dy2 - 0.0 + ey + 200 Ny2 >= 0;
Dy2 - 0.0 + ey - 200 Ny2 <= 0;
// Distancia Total
Dx2 + Dy2 = D2;

// Distancia de la escuela a 3
// Distancia en X
Dx3 - ex + 40.0 - 200 Nx3 >= -200;
Dx3 - ex + 40.0 + 200 Nx3 <= 200;
Dx3 - 40.0 + ex + 200 Nx3 >= 0;
Dx3 - 40.0 + ex - 200 Nx3 <= 0;
// Distancia en Y
Dy3 - ey + 0.0 - 200 Ny3 >= -200;
Dy3 - ey + 0.0 + 200 Ny3 <= 200;
Dy3 - 0.0 + ey + 200 Ny3 >= 0;
Dy3 - 0.0 + ey - 200 Ny3 <= 0;
// Distancia Total
Dx3 + Dy3 = D3;

// Distancia de la escuela a 4
// Distancia en X
Dx4 - ex + 50.0 - 200 Nx4 >= -200;
Dx4 - ex + 50.0 + 200 Nx4 <= 200;
Dx4 - 50.0 + ex + 200 Nx4 >= 0;
Dx4 - 50.0 + ex - 200 Nx4 <= 0;
// Distancia en Y
Dy4 - ey + 0.0 - 200 Ny4 >= -200;
Dy4 - ey + 0.0 + 200 Ny4 <= 200;
Dy4 - 0.0 + ey + 200 Ny4 >= 0;
Dy4 - 0.0 + ey - 200 Ny4 <= 0;
// Distancia Total
Dx4 + Dy4 = D4;

// Distancia de la escuela a 5
// Distancia en X
Dx5 - ex + 55.0 - 200 Nx5 >= -200;
Dx5 - ex + 55.0 + 200 Nx5 <= 200;
Dx5 - 55.0 + ex + 200 Nx5 >= 0;
Dx5 - 55.0 + ex - 200 Nx5 <= 0;
// Distancia en Y
Dy5 - ey + 0.0 - 200 Ny5 >= -200;
Dy5 - ey + 0.0 + 200 Ny5 <= 200;
Dy5 - 0.0 + ey + 200 Ny5 >= 0;
Dy5 - 0.0 + ey - 200 Ny5 <= 0;
// Distancia Total
Dx5 + Dy5 = D5;

// Distancia de la escuela a 6
// Distancia en X
Dx6 - ex + 60.0 - 200 Nx6 >= -200;
Dx6 - ex + 60.0 + 200 Nx6 <= 200;
Dx6 - 60.0 + ex + 200 Nx6 >= 0;
Dx6 - 60.0 + ex - 200 Nx6 <= 0;
// Distancia en Y
Dy6 - ey + 0.0 - 200 Ny6 >= -200;
Dy6 - ey + 0.0 + 200 Ny6 <= 200;
Dy6 - 0.0 + ey + 200 Ny6 >= 0;
Dy6 - 0.0 + ey - 200 Ny6 <= 0;
// Distancia Total
Dx6 + Dy6 = D6;


// Calculo de los condicionales de la vereda más lejana
D0 - D1 - 200 r0 >= -200;
D0 - D2 - 200 r0 >= -200;
D0 - D3 - 200 r0 >= -200;
D0 - D4 - 200 r0 >= -200;
D0 - D5 - 200 r0 >= -200;
D0 - D6 - 200 r0 >= -200;
D1 - D0 - 200 r1 >= -200;
D1 - D2 - 200 r1 >= -200;
D1 - D3 - 200 r1 >= -200;
D1 - D4 - 200 r1 >= -200;
D1 - D5 - 200 r1 >= -200;
D1 - D6 - 200 r1 >= -200;
D2 - D0 - 200 r2 >= -200;
D2 - D1 - 200 r2 >= -200;
D2 - D3 - 200 r2 >= -200;
D2 - D4 - 200 r2 >= -200;
D2 - D5 - 200 r2 >= -200;
D2 - D6 - 200 r2 >= -200;
D3 - D0 - 200 r3 >= -200;
D3 - D1 - 200 r3 >= -200;
D3 - D2 - 200 r3 >= -200;
D3 - D4 - 200 r3 >= -200;
D3 - D5 - 200 r3 >= -200;
D3 - D6 - 200 r3 >= -200;
D4 - D0 - 200 r4 >= -200;
D4 - D1 - 200 r4 >= -200;
D4 - D2 - 200 r4 >= -200;
D4 - D3 - 200 r4 >= -200;
D4 - D5 - 200 r4 >= -200;
D4 - D6 - 200 r4 >= -200;
D5 - D0 - 200 r5 >= -200;
D5 - D1 - 200 r5 >= -200;
D5 - D2 - 200 r5 >= -200;
D5 - D3 - 200 r5 >= -200;
D5 - D4 - 200 r5 >= -200;
D5 - D6 - 200 r5 >= -200;
D6 - D0 - 200 r6 >= -200;
D6 - D1 - 200 r6 >= -200;
D6 - D2 - 200 r6 >= -200;
D6 - D3 - 200 r6 >= -200;
D6 - D4 - 200 r6 >= -200;
D6 - D5 - 200 r6 >= -200;

// Solo hay una mas lejana que las demas
r0 + r1 + r2 + r3 + r4 + r5 + r6 = 1;

// Calculo de las distancias condicionadas
A0 - D0 - 200 r0 >= -200;
A0 - D0 + 200 r0 <= 200;
A0 - 200 r0 <= 0;
A1 - D1 - 200 r1 >= -200;
A1 - D1 + 200 r1 <= 200;
A1 - 200 r1 <= 0;
A2 - D2 - 200 r2 >= -200;
A2 - D2 + 200 r2 <= 200;
A2 - 200 r2 <= 0;
A3 - D3 - 200 r3 >= -200;
A3 - D3 + 200 r3 <= 200;
A3 - 200 r3 <= 0;
A4 - D4 - 200 r4 >= -200;
A4 - D4 + 200 r4 <= 200;
A4 - 200 r4 <= 0;
A5 - D5 - 200 r5 >= -200;
A5 - D5 + 200 r5 <= 200;
A5 - 200 r5 <= 0;
A6 - D6 - 200 r6 >= -200;
A6 - D6 + 200 r6 <= 200;
A6 - 200 r6 <= 0;

// Restricciones Binarias
Nx0 <= 1;
Ny0 <= 1;
Nx1 <= 1;
Ny1 <= 1;
Nx2 <= 1;
Ny2 <= 1;
Nx3 <= 1;
Ny3 <= 1;
Nx4 <= 1;
Ny4 <= 1;
Nx5 <= 1;
Ny5 <= 1;
Nx6 <= 1;
Ny6 <= 1;
r0 <= 1;
r1 <= 1;
r2 <= 1;
r3 <= 1;
r4 <= 1;
r5 <= 1;
r6 <= 1;

// Restricciones Binarias (2)
int Nx0, Ny0, Nx1, Ny1, Nx2, Ny2, Nx3, Ny3, Nx4, Ny4, Nx5, Ny5, Nx6, Ny6, r0, r1, r2, r3, r4, r5, r6;

