/* Objective function */
/*
  M  = 200
  x1 = 10
  x2 = 20
  x3 = 30
  e  = 20
*/


min: D1 + D2;

// Valor absoluto
  e      + 200 - 200 N1 >= 10;
            20 - 200 N1 <= 10;
  e      + 200 - 200 N2 >= 20;
            20 - 200 N2 <= 20;

// Distancias
  e - 10 + 200 - 200 N1                >= D1;
  e - 10 - 200 + 200 N1 - 200 + 200 r1 <= D1;
- e + 10 +       200 N1                >= D1;
- e + 10 -       200 N1 - 200 + 200 r1 <= D1;
  e - 20 + 200 - 200 N2                >= D2;
  e - 20 - 200 + 200 N2 - 200 + 200 r2 <= D2;
- e + 20 +       200 N2                >= D2;
- e + 20 -       200 N2 - 200 + 200 r2 <= D2;

// Ciudad más lejana





// De condición
200 r1 >= D1;
200 r2 >= D2;

// Binarias
N1 <= 1;
N2 <= 1;
r1 <= 1;
r2 <= 1;

r1 + r2 = 1;

int r1, r2;
int N1, N2;