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
    int ix = 0;
    for (j = 0; j < lenX; j++) {
        int x_index = ix;
        int a_index = lda * i + j;
        temp += X[x_index] * A[a_index];
        ix += incX;
    }
    int y_index = iy;
    Y[y_index] += alpha * temp;
    iy += incY;
}
}
