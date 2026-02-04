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
    jx += incX;
    if (temp == 0.) continue;
    const int i_min = (j >= U ? j - U : 0);
    const int i_max = (lenY <= j + L ? lenY : j + L + 1);
    int iy_start = ((incY) > 0 ? 0 : (lenY - 1) * (-incY));
    for (i = i_min; i < i_max; i++) {
        int offset = lda * j + (U + i - j);
        Y[iy_start + i * incY] += temp * A[offset];
    }
}
}
