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
    const int lower_bound = i - L;
    const int upper_bound = i + U + 1;
    int j_min = lower_bound > 0 ? lower_bound : 0;
    int j_max = upper_bound < lenX ? upper_bound : lenX;
    if (j_min >= j_max) {
        iy += incY;
        continue;
    }
    int jx = ((incX) > 0 ? 0 : (lenX - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L - i + j) + i * lda];
        jx += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
