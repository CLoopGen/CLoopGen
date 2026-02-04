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
    int k = j_min;
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    // Change to consecutive access by precomputing base pointer and using offset
    const float* X_base = &X[jx];
    const float* A_row = &A[i * lda + (L - i + j_min)];
    for (int offset = 0; k < j_max; k++, offset++) {
        temp += X_base[k * incX] * A_row[offset];
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
