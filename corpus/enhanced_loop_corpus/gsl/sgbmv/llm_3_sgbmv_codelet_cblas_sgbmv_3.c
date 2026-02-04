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
const int strideX = incX;
const int strideY = incY;
int base_jx = jx;
for (j = 0; j < lenX; j++) {
    const int current_jx = base_jx + j * strideX;
    const float temp = alpha * X[current_jx];
    if (temp != 0.) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy_start = ((strideY) > 0 ? 0 : (lenY - 1) * (-strideY)) + i_min * strideY;
        for (i = i_min; i < i_max; i++) {
            const int A_offset = lda * j + (U + i - j);
            const int Y_offset = iy_start + (i - i_min) * strideY;
            Y[Y_offset] += temp * A[A_offset];
        }
    }
}
}
