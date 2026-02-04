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
    float temp1 = 0.0f, temp2 = 0.0f;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    int k = j_min;
    
    // Unroll by 2 to increase arithmetic operations per iteration
    for (; k <= j_max - 2; k += 2) {
        temp1 += X[jx] * A[(L - i + k) + i * lda];
        temp2 += X[jx + incX] * A[(L - i + k + 1) + i * lda];
        jx += 2 * incX;
    }
    // Handle remaining element if any
    for (; k < j_max; k++) {
        temp1 += X[jx] * A[(L - i + k) + i * lda];
        jx += incX;
    }
    temp1 += temp2; // Combine partial sums
    Y[iy] += alpha * temp1;
    iy += incY;
}
}
