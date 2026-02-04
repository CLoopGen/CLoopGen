#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j++) {
    const double temp = alpha * X[ix];
    if (temp == 0.) {
        ix += incX;
        continue;
    }
    int iy = 0;
    const int incY_abs = incY > 0 ? incY : -incY;
    const int base_offset = incY < 0 ? (lenY - 1) * (-incY) : 0;
    for (i = 0; i < lenY; i++) {
        Y[base_offset + iy * incY] += temp * A[lda * j + i];
        iy++;
    }
    ix += incX;
}
}
