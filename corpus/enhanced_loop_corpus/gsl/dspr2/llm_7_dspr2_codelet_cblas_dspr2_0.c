#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double local_alpha = alpha;
for (i = 0; i < N; i++) {
    double x_val = X[ix];
    double y_val = Y[iy];
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j++) {
        double product_xy = local_alpha * x_val * Y[jy];
        double product_yx = local_alpha * y_val * X[jx];
        Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))] = 
            Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))] + product_xy + product_yx;
        jx += incX;
        jy += incY;
    }
    ix += incX;
    iy += incY;
}
}
