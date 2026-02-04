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
for (j = 0; j < lenX; j++) {
    const float temp = alpha * X[ix];
    if (temp != 0.) {
        for (i = 0; i < lenY; i++) {
            int offset = i * incY;
            int ay_idx = lda * j + i;
            Y[offset] += temp * A[ay_idx];
        }
    }
    ix += incX;
}
}
