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
for (j = 0; j < lenX; j++) {
    const float temp = alpha * X[jx];
    if (temp != 0.) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy_start = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        int stride = incY;
        for (int offset = 0; offset < (i_max - i_min); offset++) {
            int i = i_min + offset;
            int iy = iy_start + offset * stride;
            Y[iy] += temp * A[lda * j + (U + i - j)];
        }
    }
    jx += incX;
}
}
