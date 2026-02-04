#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *X;
extern  int incX;
extern float *Y;
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
for (i = 0; i < lenY; i++) {
    float temp = 0.;
    int j_min = 0;
    int j_max = lenX;
    if (i > L) j_min = i - L;
    if (i + U + 1 < lenX) j_max = i + U + 1;
    int jx = ((incX) > 0 ? 0 : (lenX - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L - i + j) + i * lda];
        jx += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
