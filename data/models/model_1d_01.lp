// Funcion Objetivo
min: A0 + A1;

// Puntos
// {(10,0) , (40,0)}

// Calculo de las Distancias entre la escuela y las veredas
// Distancia de la escuela a 0

// Distancia en X
Dx0 - ex + 10 - 82 Nx0 >= -82;
Dx0 - ex + 10 + 82 Nx0 <= 82;
Dx0 - 10 + ex + 82 Nx0 >= 0;
Dx0 - 10 + ex - 82 Nx0 <= 0;

// Distancia en Y
Dy0 - ey + 0 - 82 Ny0 >= -82;
Dy0 - ey + 0 + 82 Ny0 <= 82;
Dy0 - 0 + ey + 82 Ny0 >= 0;
Dy0 - 0 + ey - 82 Ny0 <= 0;

// Distancia Total
Dx0 + Dy0 = D0;

// Distancia de la escuela a 1

// Distancia en X
Dx1 - ex + 40 - 82 Nx1 >= -82;
Dx1 - ex + 40 + 82 Nx1 <= 82;
Dx1 - 40 + ex + 82 Nx1 >= 0;
Dx1 - 40 + ex - 82 Nx1 <= 0;

// Distancia en Y
Dy1 - ey + 0 - 82 Ny1 >= -82;
Dy1 - ey + 0 + 82 Ny1 <= 82;
Dy1 - 0 + ey + 82 Ny1 >= 0;
Dy1 - 0 + ey - 82 Ny1 <= 0;

// Distancia Total
Dx1 + Dy1 = D1;


// Calculo de los condicionales de la vereda m�s lejana
D0 - D1 - 82 r0 >= -82;
D1 - D0 - 82 r1 >= -82;

// Solo hay una mas lejana que las demas
r0 + r1 = 1;

// Actualizar en algun A, la distancia mas lejana
A0 - D0 - 82 r0 >= -82;
A0 - D0 + 82 r0 <= 82;
A0 - 82 r0 <= 0;
A1 - D1 - 82 r1 >= -82;
A1 - D1 + 82 r1 <= 82;
A1 - 82 r1 <= 0;

