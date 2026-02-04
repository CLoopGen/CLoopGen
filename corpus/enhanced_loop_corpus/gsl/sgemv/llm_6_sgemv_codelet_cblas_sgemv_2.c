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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.;
    int ix_base;
    for (i = 0; i < lenY; i++) {
        temp = 0.;
        ix_base = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
        for (j = 0; j < lenX; j++) {
            temp += X[ix_base + j * incX] * A[lda * i + j];
        }
        Y[iy + i * incY] += alpha * temp;
    }
}
