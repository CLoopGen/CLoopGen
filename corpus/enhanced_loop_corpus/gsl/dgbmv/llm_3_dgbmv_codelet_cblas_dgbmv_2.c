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
extern int L;
extern int U;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int strideX = incX;
const int strideY = incY;
int base_jx = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
int base_iy = iy;

for (i = 0; i < lenY; i++) {
    double temp = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = (lenX < i + U + 1 ? lenX : i + U + 1);
    int jx = base_jx + j_min * strideX;
    for (j = j_min; j < j_max; j++) {
        int a_index = (L - i + j) + i * lda;
        temp += X[jx] * A[a_index];
        jx += strideX;
    }
    int y_index = base_iy + i * strideY;
    Y[y_index] += alpha * temp;
}
iy = base_iy + lenY * strideY;
}
