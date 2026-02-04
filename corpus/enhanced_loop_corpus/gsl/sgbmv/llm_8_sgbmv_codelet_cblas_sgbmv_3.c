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
extern int jx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j += 2) {
    const float temp1 = alpha * X[jx];
    const float temp2 = (j + 1 < lenX) ? alpha * X[jx + incX] : 0.0f;
    if (temp1 != 0.) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = (lenY < j + L + 1 ? lenY : j + L + 1);
        int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY)) + i_min * incY;
        for (i = i_min; i < i_max; i++) {
            Y[iy] += temp1 * A[lda * j + (U + i - j)];
            iy += incY;
        }
    }
    if (temp2 != 0. && j + 1 < lenX) {
        const int i_min2 = (j + 1 > U ? j + 1 - U : 0);
        const int i_max2 = (lenY < j + 1 + L + 1 ? lenY : j + 1 + L + 1);
        int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY)) + i_min2 * incY;
        for (i = i_min2; i < i_max2; i++) {
            Y[iy] += temp2 * A[lda * (j + 1) + (U + i - (j + 1))];
            iy += incY;
        }
    }
    jx += 2 * incX;
}
}
