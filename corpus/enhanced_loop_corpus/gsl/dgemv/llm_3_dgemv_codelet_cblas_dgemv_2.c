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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    double temp = 0.;
    int base_a_idx = i * lda;
    int x_offset = (incX > 0 ? 0 : (lenX - 1) * (-incX));
    for (j = 0; j < lenX; j++) {
        int a_offset = base_a_idx + j;
        temp += X[x_offset] * A[a_offset];
        x_offset += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
