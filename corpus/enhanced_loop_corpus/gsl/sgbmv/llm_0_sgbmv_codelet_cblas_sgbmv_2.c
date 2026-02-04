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
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    int k = j_min;
    for (; k < j_max; k += 2) {
        temp += X[jx] * A[(L - i + k) + i * lda];
        jx += incX;
        if (k + 1 < j_max) {
            temp += X[jx] * A[(L - i + k + 1) + i * lda];
            jx += incX;
        }
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
