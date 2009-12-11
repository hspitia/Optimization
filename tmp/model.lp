// Funcion Objetivo
min: A0 + A1 + A2 + A3 + A4 + A5 + A6;

// Puntos
// {(2.2,8) , (3.6,1.7) , (1.2,5.8) , (5.5,7) , (7,8) , (9.8,5.7) , (7.6,1.3)}

// Calculo de las Distancias entre la escuela y las veredas
// Distancia de la escuela a 0

// Distancia en XDx0 - ex + 2.2 - 20 Nx0 >= -20;
Dx0 - ex + 2.2 + 20 Nx0 <= 20;
Dx0 - 2.2 + ex + 20 Nx0 >= 0;
Dx0 - 2.2 + ex - 20 Nx0 <= 0;

// Distancia en Y
Dy0 - ey + 8 - 20 Ny0 >= -20;
Dy0 - ey + 8 + 20 Ny0 <= 20;
Dy0 - 8 + ey + 20 Ny0 >= 0;
Dy0 - 8 + ey - 20 Ny0 <= 0;

// Distancia Total
Dx0 + Dy0 = D0;

// Distancia de la escuela a 1

// Distancia en XDx1 - ex + 3.6 - 20 Nx1 >= -20;
Dx1 - ex + 3.6 + 20 Nx1 <= 20;
Dx1 - 3.6 + ex + 20 Nx1 >= 0;
Dx1 - 3.6 + ex - 20 Nx1 <= 0;

// Distancia en Y
Dy1 - ey + 1.7 - 20 Ny1 >= -20;
Dy1 - ey + 1.7 + 20 Ny1 <= 20;
Dy1 - 1.7 + ey + 20 Ny1 >= 0;
Dy1 - 1.7 + ey - 20 Ny1 <= 0;

// Distancia Total
Dx1 + Dy1 = D1;

// Distancia de la escuela a 2

// Distancia en XDx2 - ex + 1.2 - 20 Nx2 >= -20;
Dx2 - ex + 1.2 + 20 Nx2 <= 20;
Dx2 - 1.2 + ex + 20 Nx2 >= 0;
Dx2 - 1.2 + ex - 20 Nx2 <= 0;

// Distancia en Y
Dy2 - ey + 5.8 - 20 Ny2 >= -20;
Dy2 - ey + 5.8 + 20 Ny2 <= 20;
Dy2 - 5.8 + ey + 20 Ny2 >= 0;
Dy2 - 5.8 + ey - 20 Ny2 <= 0;

// Distancia Total
Dx2 + Dy2 = D2;

// Distancia de la escuela a 3

// Distancia en XDx3 - ex + 5.5 - 20 Nx3 >= -20;
Dx3 - ex + 5.5 + 20 Nx3 <= 20;
Dx3 - 5.5 + ex + 20 Nx3 >= 0;
Dx3 - 5.5 + ex - 20 Nx3 <= 0;

// Distancia en Y
Dy3 - ey + 7 - 20 Ny3 >= -20;
Dy3 - ey + 7 + 20 Ny3 <= 20;
Dy3 - 7 + ey + 20 Ny3 >= 0;
Dy3 - 7 + ey - 20 Ny3 <= 0;

// Distancia Total
Dx3 + Dy3 = D3;

// Distancia de la escuela a 4

// Distancia en XDx4 - ex + 7 - 20 Nx4 >= -20;
Dx4 - ex + 7 + 20 Nx4 <= 20;
Dx4 - 7 + ex + 20 Nx4 >= 0;
Dx4 - 7 + ex - 20 Nx4 <= 0;

// Distancia en Y
Dy4 - ey + 8 - 20 Ny4 >= -20;
Dy4 - ey + 8 + 20 Ny4 <= 20;
Dy4 - 8 + ey + 20 Ny4 >= 0;
Dy4 - 8 + ey - 20 Ny4 <= 0;

// Distancia Total
Dx4 + Dy4 = D4;

// Distancia de la escuela a 5

// Distancia en XDx5 - ex + 9.8 - 20 Nx5 >= -20;
Dx5 - ex + 9.8 + 20 Nx5 <= 20;
Dx5 - 9.8 + ex + 20 Nx5 >= 0;
Dx5 - 9.8 + ex - 20 Nx5 <= 0;

// Distancia en Y
Dy5 - ey + 5.7 - 20 Ny5 >= -20;
Dy5 - ey + 5.7 + 20 Ny5 <= 20;
Dy5 - 5.7 + ey + 20 Ny5 >= 0;
Dy5 - 5.7 + ey - 20 Ny5 <= 0;

// Distancia Total
Dx5 + Dy5 = D5;

// Distancia de la escuela a 6

// Distancia en XDx6 - ex + 7.6 - 20 Nx6 >= -20;
Dx6 - ex + 7.6 + 20 Nx6 <= 20;
Dx6 - 7.6 + ex + 20 Nx6 >= 0;
Dx6 - 7.6 + ex - 20 Nx6 <= 0;

// Distancia en Y
Dy6 - ey + 1.3 - 20 Ny6 >= -20;
Dy6 - ey + 1.3 + 20 Ny6 <= 20;
Dy6 - 1.3 + ey + 20 Ny6 >= 0;
Dy6 - 1.3 + ey - 20 Ny6 <= 0;

// Distancia Total
Dx6 + Dy6 = D6;


// Calculo de los condicionales de la vereda más lejana
D0 - D1 - 20 r0 >= -20;
D0 - D2 - 20 r0 >= -20;
D0 - D3 - 20 r0 >= -20;
D0 - D4 - 20 r0 >= -20;
D0 - D5 - 20 r0 >= -20;
D0 - D6 - 20 r0 >= -20;
D1 - D0 - 20 r1 >= -20;
D1 - D2 - 20 r1 >= -20;
D1 - D3 - 20 r1 >= -20;
D1 - D4 - 20 r1 >= -20;
D1 - D5 - 20 r1 >= -20;
D1 - D6 - 20 r1 >= -20;
D2 - D0 - 20 r2 >= -20;
D2 - D1 - 20 r2 >= -20;
D2 - D3 - 20 r2 >= -20;
D2 - D4 - 20 r2 >= -20;
D2 - D5 - 20 r2 >= -20;
D2 - D6 - 20 r2 >= -20;
D3 - D0 - 20 r3 >= -20;
D3 - D1 - 20 r3 >= -20;
D3 - D2 - 20 r3 >= -20;
D3 - D4 - 20 r3 >= -20;
D3 - D5 - 20 r3 >= -20;
D3 - D6 - 20 r3 >= -20;
D4 - D0 - 20 r4 >= -20;
D4 - D1 - 20 r4 >= -20;
D4 - D2 - 20 r4 >= -20;
D4 - D3 - 20 r4 >= -20;
D4 - D5 - 20 r4 >= -20;
D4 - D6 - 20 r4 >= -20;
D5 - D0 - 20 r5 >= -20;
D5 - D1 - 20 r5 >= -20;
D5 - D2 - 20 r5 >= -20;
D5 - D3 - 20 r5 >= -20;
D5 - D4 - 20 r5 >= -20;
D5 - D6 - 20 r5 >= -20;
D6 - D0 - 20 r6 >= -20;
D6 - D1 - 20 r6 >= -20;
D6 - D2 - 20 r6 >= -20;
D6 - D3 - 20 r6 >= -20;
D6 - D4 - 20 r6 >= -20;
D6 - D5 - 20 r6 >= -20;

// Solo hay una mas lejana que las demas
r0 + r1 + r2 + r3 + r4 + r5 + r6 = 1;

// Actualizar en algun A, la distancia mas lejana
A0 - D0 - 20 r0 >= -20;
A0 - D0 + 20 r0 <= 20;
A0 - 20 r0 <= 0;
A1 - D1 - 20 r1 >= -20;
A1 - D1 + 20 r1 <= 20;
A1 - 20 r1 <= 0;
A2 - D2 - 20 r2 >= -20;
A2 - D2 + 20 r2 <= 20;
A2 - 20 r2 <= 0;
A3 - D3 - 20 r3 >= -20;
A3 - D3 + 20 r3 <= 20;
A3 - 20 r3 <= 0;
A4 - D4 - 20 r4 >= -20;
A4 - D4 + 20 r4 <= 20;
A4 - 20 r4 <= 0;
A5 - D5 - 20 r5 >= -20;
A5 - D5 + 20 r5 <= 20;
A5 - 20 r5 <= 0;
A6 - D6 - 20 r6 >= -20;
A6 - D6 + 20 r6 <= 20;
A6 - 20 r6 <= 0;

// Restricciones Binarias
bin Nx0, Ny0, Nx1, Ny1, Nx2, Ny2, Nx3, Ny3, Nx4, Ny4, Nx5, Ny5, Nx6, Ny6, r0, r1, r2, r3, r4, r5, r6;
