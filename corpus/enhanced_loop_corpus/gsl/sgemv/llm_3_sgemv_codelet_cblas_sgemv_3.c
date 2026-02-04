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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int strideA = 1;
const int strideY = incY;
int base_ix = ix;
for (j = 0; j < lenX; j++) {
    const float temp = alpha * X[base_ix];
    if (temp != 0.) {
        int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY));
        for (i = 0; i < lenY; i++) {
            int a_index = j + i * lda;
            Y[iy] += temp * A[a_index];
            iy += strideY;
        }
    }
    base_ix += incX;
}
}
