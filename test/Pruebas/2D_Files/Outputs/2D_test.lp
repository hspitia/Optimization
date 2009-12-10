// Funcion Objetivo
min: + A0 + A1 + A2 + A3 + A4 + A5 + A6 + A7 + A8 + A9 + A10;

// Points
// {[4.0;1.0] , [8.0;1.0] , [2.0;3.0] , [7.0;3.0] , [4.0;4.0] , [3.0;5.0] , [6.0;6.0] , [4.0;5.0] , [4.0;4.0] , [5.0;3.0] , [7.0;3.0]}

// Calculo de las Distancias entre la escuela y las veredas
// Distancia de la escuela a 0
// Distancia en X
Dx0 - ex + 4.0 - 18 Nx0 >= -18;
Dx0 - ex + 4.0 + 18 Nx0 <= 18;
Dx0 - 4.0 + ex + 18 Nx0 >= 0;
Dx0 - 4.0 + ex - 18 Nx0 <= 0;
// Distancia en Y
Dy0 - ey + 1.0 - 18 Ny0 >= -18;
Dy0 - ey + 1.0 + 18 Ny0 <= 18;
Dy0 - 1.0 + ey + 18 Ny0 >= 0;
Dy0 - 1.0 + ey - 18 Ny0 <= 0;
// Distancia Total
Dx0 + Dy0 = D0;

// Distancia de la escuela a 1
// Distancia en X
Dx1 - ex + 8.0 - 18 Nx1 >= -18;
Dx1 - ex + 8.0 + 18 Nx1 <= 18;
Dx1 - 8.0 + ex + 18 Nx1 >= 0;
Dx1 - 8.0 + ex - 18 Nx1 <= 0;
// Distancia en Y
Dy1 - ey + 1.0 - 18 Ny1 >= -18;
Dy1 - ey + 1.0 + 18 Ny1 <= 18;
Dy1 - 1.0 + ey + 18 Ny1 >= 0;
Dy1 - 1.0 + ey - 18 Ny1 <= 0;
// Distancia Total
Dx1 + Dy1 = D1;

// Distancia de la escuela a 2
// Distancia en X
Dx2 - ex + 2.0 - 18 Nx2 >= -18;
Dx2 - ex + 2.0 + 18 Nx2 <= 18;
Dx2 - 2.0 + ex + 18 Nx2 >= 0;
Dx2 - 2.0 + ex - 18 Nx2 <= 0;
// Distancia en Y
Dy2 - ey + 3.0 - 18 Ny2 >= -18;
Dy2 - ey + 3.0 + 18 Ny2 <= 18;
Dy2 - 3.0 + ey + 18 Ny2 >= 0;
Dy2 - 3.0 + ey - 18 Ny2 <= 0;
// Distancia Total
Dx2 + Dy2 = D2;

// Distancia de la escuela a 3
// Distancia en X
Dx3 - ex + 7.0 - 18 Nx3 >= -18;
Dx3 - ex + 7.0 + 18 Nx3 <= 18;
Dx3 - 7.0 + ex + 18 Nx3 >= 0;
Dx3 - 7.0 + ex - 18 Nx3 <= 0;
// Distancia en Y
Dy3 - ey + 3.0 - 18 Ny3 >= -18;
Dy3 - ey + 3.0 + 18 Ny3 <= 18;
Dy3 - 3.0 + ey + 18 Ny3 >= 0;
Dy3 - 3.0 + ey - 18 Ny3 <= 0;
// Distancia Total
Dx3 + Dy3 = D3;

// Distancia de la escuela a 4
// Distancia en X
Dx4 - ex + 4.0 - 18 Nx4 >= -18;
Dx4 - ex + 4.0 + 18 Nx4 <= 18;
Dx4 - 4.0 + ex + 18 Nx4 >= 0;
Dx4 - 4.0 + ex - 18 Nx4 <= 0;
// Distancia en Y
Dy4 - ey + 4.0 - 18 Ny4 >= -18;
Dy4 - ey + 4.0 + 18 Ny4 <= 18;
Dy4 - 4.0 + ey + 18 Ny4 >= 0;
Dy4 - 4.0 + ey - 18 Ny4 <= 0;
// Distancia Total
Dx4 + Dy4 = D4;

// Distancia de la escuela a 5
// Distancia en X
Dx5 - ex + 3.0 - 18 Nx5 >= -18;
Dx5 - ex + 3.0 + 18 Nx5 <= 18;
Dx5 - 3.0 + ex + 18 Nx5 >= 0;
Dx5 - 3.0 + ex - 18 Nx5 <= 0;
// Distancia en Y
Dy5 - ey + 5.0 - 18 Ny5 >= -18;
Dy5 - ey + 5.0 + 18 Ny5 <= 18;
Dy5 - 5.0 + ey + 18 Ny5 >= 0;
Dy5 - 5.0 + ey - 18 Ny5 <= 0;
// Distancia Total
Dx5 + Dy5 = D5;

// Distancia de la escuela a 6
// Distancia en X
Dx6 - ex + 6.0 - 18 Nx6 >= -18;
Dx6 - ex + 6.0 + 18 Nx6 <= 18;
Dx6 - 6.0 + ex + 18 Nx6 >= 0;
Dx6 - 6.0 + ex - 18 Nx6 <= 0;
// Distancia en Y
Dy6 - ey + 6.0 - 18 Ny6 >= -18;
Dy6 - ey + 6.0 + 18 Ny6 <= 18;
Dy6 - 6.0 + ey + 18 Ny6 >= 0;
Dy6 - 6.0 + ey - 18 Ny6 <= 0;
// Distancia Total
Dx6 + Dy6 = D6;

// Distancia de la escuela a 7
// Distancia en X
Dx7 - ex + 4.0 - 18 Nx7 >= -18;
Dx7 - ex + 4.0 + 18 Nx7 <= 18;
Dx7 - 4.0 + ex + 18 Nx7 >= 0;
Dx7 - 4.0 + ex - 18 Nx7 <= 0;
// Distancia en Y
Dy7 - ey + 5.0 - 18 Ny7 >= -18;
Dy7 - ey + 5.0 + 18 Ny7 <= 18;
Dy7 - 5.0 + ey + 18 Ny7 >= 0;
Dy7 - 5.0 + ey - 18 Ny7 <= 0;
// Distancia Total
Dx7 + Dy7 = D7;

// Distancia de la escuela a 8
// Distancia en X
Dx8 - ex + 4.0 - 18 Nx8 >= -18;
Dx8 - ex + 4.0 + 18 Nx8 <= 18;
Dx8 - 4.0 + ex + 18 Nx8 >= 0;
Dx8 - 4.0 + ex - 18 Nx8 <= 0;
// Distancia en Y
Dy8 - ey + 4.0 - 18 Ny8 >= -18;
Dy8 - ey + 4.0 + 18 Ny8 <= 18;
Dy8 - 4.0 + ey + 18 Ny8 >= 0;
Dy8 - 4.0 + ey - 18 Ny8 <= 0;
// Distancia Total
Dx8 + Dy8 = D8;

// Distancia de la escuela a 9
// Distancia en X
Dx9 - ex + 5.0 - 18 Nx9 >= -18;
Dx9 - ex + 5.0 + 18 Nx9 <= 18;
Dx9 - 5.0 + ex + 18 Nx9 >= 0;
Dx9 - 5.0 + ex - 18 Nx9 <= 0;
// Distancia en Y
Dy9 - ey + 3.0 - 18 Ny9 >= -18;
Dy9 - ey + 3.0 + 18 Ny9 <= 18;
Dy9 - 3.0 + ey + 18 Ny9 >= 0;
Dy9 - 3.0 + ey - 18 Ny9 <= 0;
// Distancia Total
Dx9 + Dy9 = D9;

// Distancia de la escuela a 10
// Distancia en X
Dx10 - ex + 7.0 - 18 Nx10 >= -18;
Dx10 - ex + 7.0 + 18 Nx10 <= 18;
Dx10 - 7.0 + ex + 18 Nx10 >= 0;
Dx10 - 7.0 + ex - 18 Nx10 <= 0;
// Distancia en Y
Dy10 - ey + 3.0 - 18 Ny10 >= -18;
Dy10 - ey + 3.0 + 18 Ny10 <= 18;
Dy10 - 3.0 + ey + 18 Ny10 >= 0;
Dy10 - 3.0 + ey - 18 Ny10 <= 0;
// Distancia Total
Dx10 + Dy10 = D10;


// Calculo de los condicionales de la vereda m�s lejana
D0 - D1 - 18 r0 >= -18;
D0 - D2 - 18 r0 >= -18;
D0 - D3 - 18 r0 >= -18;
D0 - D4 - 18 r0 >= -18;
D0 - D5 - 18 r0 >= -18;
D0 - D6 - 18 r0 >= -18;
D0 - D7 - 18 r0 >= -18;
D0 - D8 - 18 r0 >= -18;
D0 - D9 - 18 r0 >= -18;
D0 - D10 - 18 r0 >= -18;
D1 - D0 - 18 r1 >= -18;
D1 - D2 - 18 r1 >= -18;
D1 - D3 - 18 r1 >= -18;
D1 - D4 - 18 r1 >= -18;
D1 - D5 - 18 r1 >= -18;
D1 - D6 - 18 r1 >= -18;
D1 - D7 - 18 r1 >= -18;
D1 - D8 - 18 r1 >= -18;
D1 - D9 - 18 r1 >= -18;
D1 - D10 - 18 r1 >= -18;
D2 - D0 - 18 r2 >= -18;
D2 - D1 - 18 r2 >= -18;
D2 - D3 - 18 r2 >= -18;
D2 - D4 - 18 r2 >= -18;
D2 - D5 - 18 r2 >= -18;
D2 - D6 - 18 r2 >= -18;
D2 - D7 - 18 r2 >= -18;
D2 - D8 - 18 r2 >= -18;
D2 - D9 - 18 r2 >= -18;
D2 - D10 - 18 r2 >= -18;
D3 - D0 - 18 r3 >= -18;
D3 - D1 - 18 r3 >= -18;
D3 - D2 - 18 r3 >= -18;
D3 - D4 - 18 r3 >= -18;
D3 - D5 - 18 r3 >= -18;
D3 - D6 - 18 r3 >= -18;
D3 - D7 - 18 r3 >= -18;
D3 - D8 - 18 r3 >= -18;
D3 - D9 - 18 r3 >= -18;
D3 - D10 - 18 r3 >= -18;
D4 - D0 - 18 r4 >= -18;
D4 - D1 - 18 r4 >= -18;
D4 - D2 - 18 r4 >= -18;
D4 - D3 - 18 r4 >= -18;
D4 - D5 - 18 r4 >= -18;
D4 - D6 - 18 r4 >= -18;
D4 - D7 - 18 r4 >= -18;
D4 - D8 - 18 r4 >= -18;
D4 - D9 - 18 r4 >= -18;
D4 - D10 - 18 r4 >= -18;
D5 - D0 - 18 r5 >= -18;
D5 - D1 - 18 r5 >= -18;
D5 - D2 - 18 r5 >= -18;
D5 - D3 - 18 r5 >= -18;
D5 - D4 - 18 r5 >= -18;
D5 - D6 - 18 r5 >= -18;
D5 - D7 - 18 r5 >= -18;
D5 - D8 - 18 r5 >= -18;
D5 - D9 - 18 r5 >= -18;
D5 - D10 - 18 r5 >= -18;
D6 - D0 - 18 r6 >= -18;
D6 - D1 - 18 r6 >= -18;
D6 - D2 - 18 r6 >= -18;
D6 - D3 - 18 r6 >= -18;
D6 - D4 - 18 r6 >= -18;
D6 - D5 - 18 r6 >= -18;
D6 - D7 - 18 r6 >= -18;
D6 - D8 - 18 r6 >= -18;
D6 - D9 - 18 r6 >= -18;
D6 - D10 - 18 r6 >= -18;
D7 - D0 - 18 r7 >= -18;
D7 - D1 - 18 r7 >= -18;
D7 - D2 - 18 r7 >= -18;
D7 - D3 - 18 r7 >= -18;
D7 - D4 - 18 r7 >= -18;
D7 - D5 - 18 r7 >= -18;
D7 - D6 - 18 r7 >= -18;
D7 - D8 - 18 r7 >= -18;
D7 - D9 - 18 r7 >= -18;
D7 - D10 - 18 r7 >= -18;
D8 - D0 - 18 r8 >= -18;
D8 - D1 - 18 r8 >= -18;
D8 - D2 - 18 r8 >= -18;
D8 - D3 - 18 r8 >= -18;
D8 - D4 - 18 r8 >= -18;
D8 - D5 - 18 r8 >= -18;
D8 - D6 - 18 r8 >= -18;
D8 - D7 - 18 r8 >= -18;
D8 - D9 - 18 r8 >= -18;
D8 - D10 - 18 r8 >= -18;
D9 - D0 - 18 r9 >= -18;
D9 - D1 - 18 r9 >= -18;
D9 - D2 - 18 r9 >= -18;
D9 - D3 - 18 r9 >= -18;
D9 - D4 - 18 r9 >= -18;
D9 - D5 - 18 r9 >= -18;
D9 - D6 - 18 r9 >= -18;
D9 - D7 - 18 r9 >= -18;
D9 - D8 - 18 r9 >= -18;
D9 - D10 - 18 r9 >= -18;
D10 - D0 - 18 r10 >= -18;
D10 - D1 - 18 r10 >= -18;
D10 - D2 - 18 r10 >= -18;
D10 - D3 - 18 r10 >= -18;
D10 - D4 - 18 r10 >= -18;
D10 - D5 - 18 r10 >= -18;
D10 - D6 - 18 r10 >= -18;
D10 - D7 - 18 r10 >= -18;
D10 - D8 - 18 r10 >= -18;
D10 - D9 - 18 r10 >= -18;

// Solo hay una mas lejana que las demas
r0 + r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10 = 1;

// Calculo de las distancias condicionadas
A0 - D0 - 18 r0 >= -18;
A0 - D0 + 18 r0 <= 18;
A0 - 18 r0 <= 0;
A1 - D1 - 18 r1 >= -18;
A1 - D1 + 18 r1 <= 18;
A1 - 18 r1 <= 0;
A2 - D2 - 18 r2 >= -18;
A2 - D2 + 18 r2 <= 18;
A2 - 18 r2 <= 0;
A3 - D3 - 18 r3 >= -18;
A3 - D3 + 18 r3 <= 18;
A3 - 18 r3 <= 0;
A4 - D4 - 18 r4 >= -18;
A4 - D4 + 18 r4 <= 18;
A4 - 18 r4 <= 0;
A5 - D5 - 18 r5 >= -18;
A5 - D5 + 18 r5 <= 18;
A5 - 18 r5 <= 0;
A6 - D6 - 18 r6 >= -18;
A6 - D6 + 18 r6 <= 18;
A6 - 18 r6 <= 0;
A7 - D7 - 18 r7 >= -18;
A7 - D7 + 18 r7 <= 18;
A7 - 18 r7 <= 0;
A8 - D8 - 18 r8 >= -18;
A8 - D8 + 18 r8 <= 18;
A8 - 18 r8 <= 0;
A9 - D9 - 18 r9 >= -18;
A9 - D9 + 18 r9 <= 18;
A9 - 18 r9 <= 0;
A10 - D10 - 18 r10 >= -18;
A10 - D10 + 18 r10 <= 18;
A10 - 18 r10 <= 0;

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
Nx7 <= 1;
Ny7 <= 1;
Nx8 <= 1;
Ny8 <= 1;
Nx9 <= 1;
Ny9 <= 1;
Nx10 <= 1;
Ny10 <= 1;
r0 <= 1;
r1 <= 1;
r2 <= 1;
r3 <= 1;
r4 <= 1;
r5 <= 1;
r6 <= 1;
r7 <= 1;
r8 <= 1;
r9 <= 1;
r10 <= 1;
//r5 = 1;

// Restricciones Binarias (2)
int Nx0, Ny0, Nx1, Ny1, Nx2, Ny2, Nx3, Ny3, Nx4, Ny4, Nx5, Ny5, Nx6, Ny6, Nx7, Ny7, Nx8, Ny8, Nx9, Ny9, Nx10, Ny10, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;

