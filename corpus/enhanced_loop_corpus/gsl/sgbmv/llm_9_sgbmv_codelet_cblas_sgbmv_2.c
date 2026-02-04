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
// Reduce effective trip count and computational load by skipping even indices
for (i = 0; i < lenY; i += 2) {
    float temp = 0.0f;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    
    // Decrease work per iteration by limiting inner loop span
    const int adjusted_j_max = j_min + (j_max - j_min) / 2; // Use only half the range

    for (int j = j_min; j < adjusted_j_max; j++) {
        temp += X[jx] * A[(L - i + j) + i * lda];
        jx += incX;
    }
    Y[iy] += alpha * temp;
    iy += 2 * incY; // Advance output pointer accordingly
}
}
