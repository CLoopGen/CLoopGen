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
for (i = 0; i < lenY; i++) {
    float temp = 0.0f;
    int j = 0;
    int ix = (incX > 0) ? 0 : (lenX - 1) * (-incX);
    for (; j < lenX; j++) {
        if (ix >= 0) {
            temp += X[ix] * A[lda * i + j];
        }
        ix += incX;
    }
    if (iy >= 0) {
        Y[iy] += alpha * temp;
    }
    iy += incY;
}
}
