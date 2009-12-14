// Funcion Objetivo
min: L;

// Puntos
// {[2.2,8] , [3.6,1.7] , [1.2,5.8] , [5.5,7] , [7,8] , [9.8,5.7] , [7.6,1.3]}

// Calculo de las Distancias entre la escuela y las veredas
// Distancia de la escuela a 1
// Distancia en X
dx1 - ex + 2.2 - 20 Nx1 >= -20;
dx1 - ex + 2.2 + 20 Nx1 <= 20;
dx1 - 2.2 + ex + 20 Nx1 >= 0;
dx1 - 2.2 + ex - 20 Nx1 <= 0;
// Distancia en Y
dy1 - ey + 8 - 20 Ny1 >= -20;
dy1 - ey + 8 + 20 Ny1 <= 20;
dy1 - 8 + ey + 20 Ny1 >= 0;
dy1 - 8 + ey - 20 Ny1 <= 0;
// Distancia Total
dx1 + dy1 = D1;

// Distancia de la escuela a 2
// Distancia en X
dx2 - ex + 3.6 - 20 Nx2 >= -20;
dx2 - ex + 3.6 + 20 Nx2 <= 20;
dx2 - 3.6 + ex + 20 Nx2 >= 0;
dx2 - 3.6 + ex - 20 Nx2 <= 0;
// Distancia en Y
dy2 - ey + 1.7 - 20 Ny2 >= -20;
dy2 - ey + 1.7 + 20 Ny2 <= 20;
dy2 - 1.7 + ey + 20 Ny2 >= 0;
dy2 - 1.7 + ey - 20 Ny2 <= 0;
// Distancia Total
dx2 + dy2 = D2;

// Distancia de la escuela a 3
// Distancia en X
dx3 - ex + 1.2 - 20 Nx3 >= -20;
dx3 - ex + 1.2 + 20 Nx3 <= 20;
dx3 - 1.2 + ex + 20 Nx3 >= 0;
dx3 - 1.2 + ex - 20 Nx3 <= 0;
// Distancia en Y
dy3 - ey + 5.8 - 20 Ny3 >= -20;
dy3 - ey + 5.8 + 20 Ny3 <= 20;
dy3 - 5.8 + ey + 20 Ny3 >= 0;
dy3 - 5.8 + ey - 20 Ny3 <= 0;
// Distancia Total
dx3 + dy3 = D3;

// Distancia de la escuela a 4
// Distancia en X
dx4 - ex + 5.5 - 20 Nx4 >= -20;
dx4 - ex + 5.5 + 20 Nx4 <= 20;
dx4 - 5.5 + ex + 20 Nx4 >= 0;
dx4 - 5.5 + ex - 20 Nx4 <= 0;
// Distancia en Y
dy4 - ey + 7 - 20 Ny4 >= -20;
dy4 - ey + 7 + 20 Ny4 <= 20;
dy4 - 7 + ey + 20 Ny4 >= 0;
dy4 - 7 + ey - 20 Ny4 <= 0;
// Distancia Total
dx4 + dy4 = D4;

// Distancia de la escuela a 5
// Distancia en X
dx5 - ex + 7 - 20 Nx5 >= -20;
dx5 - ex + 7 + 20 Nx5 <= 20;
dx5 - 7 + ex + 20 Nx5 >= 0;
dx5 - 7 + ex - 20 Nx5 <= 0;
// Distancia en Y
dy5 - ey + 8 - 20 Ny5 >= -20;
dy5 - ey + 8 + 20 Ny5 <= 20;
dy5 - 8 + ey + 20 Ny5 >= 0;
dy5 - 8 + ey - 20 Ny5 <= 0;
// Distancia Total
dx5 + dy5 = D5;

// Distancia de la escuela a 6
// Distancia en X
dx6 - ex + 9.8 - 20 Nx6 >= -20;
dx6 - ex + 9.8 + 20 Nx6 <= 20;
dx6 - 9.8 + ex + 20 Nx6 >= 0;
dx6 - 9.8 + ex - 20 Nx6 <= 0;
// Distancia en Y
dy6 - ey + 5.7 - 20 Ny6 >= -20;
dy6 - ey + 5.7 + 20 Ny6 <= 20;
dy6 - 5.7 + ey + 20 Ny6 >= 0;
dy6 - 5.7 + ey - 20 Ny6 <= 0;
// Distancia Total
dx6 + dy6 = D6;

// Distancia de la escuela a 7
// Distancia en X
dx7 - ex + 7.6 - 20 Nx7 >= -20;
dx7 - ex + 7.6 + 20 Nx7 <= 20;
dx7 - 7.6 + ex + 20 Nx7 >= 0;
dx7 - 7.6 + ex - 20 Nx7 <= 0;
// Distancia en Y
dy7 - ey + 1.3 - 20 Ny7 >= -20;
dy7 - ey + 1.3 + 20 Ny7 <= 20;
dy7 - 1.3 + ey + 20 Ny7 >= 0;
dy7 - 1.3 + ey - 20 Ny7 <= 0;
// Distancia Total
dx7 + dy7 = D7;


// Calculo de los condicionales de la vereda más lejana
L >= D1;
L >= D2;
L >= D3;
L >= D4;
L >= D5;
L >= D6;
L >= D7;

// Restricciones Binarias
// bin Nx1, Ny1, Nx2, Ny2, Nx3, Ny3, Nx4, Ny4, Nx5, Ny5, Nx6, Ny6, Nx7, Ny7;
