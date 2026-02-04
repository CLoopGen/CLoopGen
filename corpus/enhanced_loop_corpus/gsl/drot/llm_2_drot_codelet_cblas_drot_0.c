#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern  double c;
extern  double s;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const int index_x = i * incX;
    const int index_y = i * incY;
    const double x = X[index_x];
    const double y = Y[index_y];
    X[index_x] = c * x + s * y;
    Y[index_y] = -s * x + c * y;
}
}
