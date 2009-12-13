// Funcion Objetivo
min: A0 + A1 + A2 + A3 + A4 + A5 + A6;

// Puntos
// {(2.2,8) , (3.6,1.7) , (1.2,5.8) , (5.5,7) , (7,8) , (9.8,5.7) , (7.6,1.3)}

// Calculo de las Distancias entre la escuela y las veredas
// Distancia de la escuela a 0

// Distancia en X
Dx0 - ex + 2.2 - 50 Nx0 >= -50;
Dx0 - ex + 2.2 + 50 Nx0 <= 50;
Dx0 - 2.2 + ex + 50 Nx0 >= 0;
Dx0 - 2.2 + ex - 50 Nx0 <= 0;

// Distancia en Y
Dy0 - ey + 8 - 50 Ny0 >= -50;
Dy0 - ey + 8 + 50 Ny0 <= 50;
Dy0 - 8 + ey + 50 Ny0 >= 0;
Dy0 - 8 + ey - 50 Ny0 <= 0;

// Distancia Total
Dx0 + Dy0 = D0;

// Distancia de la escuela a 1

// Distancia en X
Dx1 - ex + 3.6 - 50 Nx1 >= -50;
Dx1 - ex + 3.6 + 50 Nx1 <= 50;
Dx1 - 3.6 + ex + 50 Nx1 >= 0;
Dx1 - 3.6 + ex - 50 Nx1 <= 0;

// Distancia en Y
Dy1 - ey + 1.7 - 50 Ny1 >= -50;
Dy1 - ey + 1.7 + 50 Ny1 <= 50;
Dy1 - 1.7 + ey + 50 Ny1 >= 0;
Dy1 - 1.7 + ey - 50 Ny1 <= 0;

// Distancia Total
Dx1 + Dy1 = D1;

// Distancia de la escuela a 2

// Distancia en X
Dx2 - ex + 1.2 - 50 Nx2 >= -50;
Dx2 - ex + 1.2 + 50 Nx2 <= 50;
Dx2 - 1.2 + ex + 50 Nx2 >= 0;
Dx2 - 1.2 + ex - 50 Nx2 <= 0;

// Distancia en Y
Dy2 - ey + 5.8 - 50 Ny2 >= -50;
Dy2 - ey + 5.8 + 50 Ny2 <= 50;
Dy2 - 5.8 + ey + 50 Ny2 >= 0;
Dy2 - 5.8 + ey - 50 Ny2 <= 0;

// Distancia Total
Dx2 + Dy2 = D2;

// Distancia de la escuela a 3

// Distancia en X
Dx3 - ex + 5.5 - 50 Nx3 >= -50;
Dx3 - ex + 5.5 + 50 Nx3 <= 50;
Dx3 - 5.5 + ex + 50 Nx3 >= 0;
Dx3 - 5.5 + ex - 50 Nx3 <= 0;

// Distancia en Y
Dy3 - ey + 7 - 50 Ny3 >= -50;
Dy3 - ey + 7 + 50 Ny3 <= 50;
Dy3 - 7 + ey + 50 Ny3 >= 0;
Dy3 - 7 + ey - 50 Ny3 <= 0;

// Distancia Total
Dx3 + Dy3 = D3;

// Distancia de la escuela a 4

// Distancia en X
Dx4 - ex + 7 - 50 Nx4 >= -50;
Dx4 - ex + 7 + 50 Nx4 <= 50;
Dx4 - 7 + ex + 50 Nx4 >= 0;
Dx4 - 7 + ex - 50 Nx4 <= 0;

// Distancia en Y
Dy4 - ey + 8 - 50 Ny4 >= -50;
Dy4 - ey + 8 + 50 Ny4 <= 50;
Dy4 - 8 + ey + 50 Ny4 >= 0;
Dy4 - 8 + ey - 50 Ny4 <= 0;

// Distancia Total
Dx4 + Dy4 = D4;

// Distancia de la escuela a 5

// Distancia en X
Dx5 - ex + 9.8 - 50 Nx5 >= -50;
Dx5 - ex + 9.8 + 50 Nx5 <= 50;
Dx5 - 9.8 + ex + 50 Nx5 >= 0;
Dx5 - 9.8 + ex - 50 Nx5 <= 0;

// Distancia en Y
Dy5 - ey + 5.7 - 50 Ny5 >= -50;
Dy5 - ey + 5.7 + 50 Ny5 <= 50;
Dy5 - 5.7 + ey + 50 Ny5 >= 0;
Dy5 - 5.7 + ey - 50 Ny5 <= 0;

// Distancia Total
Dx5 + Dy5 = D5;

// Distancia de la escuela a 6

// Distancia en X
Dx6 - ex + 7.6 - 50 Nx6 >= -50;
Dx6 - ex + 7.6 + 50 Nx6 <= 50;
Dx6 - 7.6 + ex + 50 Nx6 >= 0;
Dx6 - 7.6 + ex - 50 Nx6 <= 0;

// Distancia en Y
Dy6 - ey + 1.3 - 50 Ny6 >= -50;
Dy6 - ey + 1.3 + 50 Ny6 <= 50;
Dy6 - 1.3 + ey + 50 Ny6 >= 0;
Dy6 - 1.3 + ey - 50 Ny6 <= 0;

// Distancia Total
Dx6 + Dy6 = D6;


// Calculo de los condicionales de la vereda más lejana
D0 - D1 - 50 r0 >= -50;
D0 - D2 - 50 r0 >= -50;
D0 - D3 - 50 r0 >= -50;
D0 - D4 - 50 r0 >= -50;
D0 - D5 - 50 r0 >= -50;
D0 - D6 - 50 r0 >= -50;
D1 - D0 - 50 r1 >= -50;
D1 - D2 - 50 r1 >= -50;
D1 - D3 - 50 r1 >= -50;
D1 - D4 - 50 r1 >= -50;
D1 - D5 - 50 r1 >= -50;
D1 - D6 - 50 r1 >= -50;
D2 - D0 - 50 r2 >= -50;
D2 - D1 - 50 r2 >= -50;
D2 - D3 - 50 r2 >= -50;
D2 - D4 - 50 r2 >= -50;
D2 - D5 - 50 r2 >= -50;
D2 - D6 - 50 r2 >= -50;
D3 - D0 - 50 r3 >= -50;
D3 - D1 - 50 r3 >= -50;
D3 - D2 - 50 r3 >= -50;
D3 - D4 - 50 r3 >= -50;
D3 - D5 - 50 r3 >= -50;
D3 - D6 - 50 r3 >= -50;
D4 - D0 - 50 r4 >= -50;
D4 - D1 - 50 r4 >= -50;
D4 - D2 - 50 r4 >= -50;
D4 - D3 - 50 r4 >= -50;
D4 - D5 - 50 r4 >= -50;
D4 - D6 - 50 r4 >= -50;
D5 - D0 - 50 r5 >= -50;
D5 - D1 - 50 r5 >= -50;
D5 - D2 - 50 r5 >= -50;
D5 - D3 - 50 r5 >= -50;
D5 - D4 - 50 r5 >= -50;
D5 - D6 - 50 r5 >= -50;
D6 - D0 - 50 r6 >= -50;
D6 - D1 - 50 r6 >= -50;
D6 - D2 - 50 r6 >= -50;
D6 - D3 - 50 r6 >= -50;
D6 - D4 - 50 r6 >= -50;
D6 - D5 - 50 r6 >= -50;

// Solo hay una mas lejana que las demas
r0 + r1 + r2 + r3 + r4 + r5 + r6 = 1;

// Actualizar en algun A, la distancia mas lejana
A0 - D0 - 50 r0 >= -50;
A0 - D0 + 50 r0 <= 50;
A0 - 50 r0 <= 0;
A1 - D1 - 50 r1 >= -50;
A1 - D1 + 50 r1 <= 50;
A1 - 50 r1 <= 0;
A2 - D2 - 50 r2 >= -50;
A2 - D2 + 50 r2 <= 50;
A2 - 50 r2 <= 0;
A3 - D3 - 50 r3 >= -50;
A3 - D3 + 50 r3 <= 50;
A3 - 50 r3 <= 0;
A4 - D4 - 50 r4 >= -50;
A4 - D4 + 50 r4 <= 50;
A4 - 50 r4 <= 0;
A5 - D5 - 50 r5 >= -50;
A5 - D5 + 50 r5 <= 50;
A5 - 50 r5 <= 0;
A6 - D6 - 50 r6 >= -50;
A6 - D6 + 50 r6 <= 50;
A6 - 50 r6 <= 0;
