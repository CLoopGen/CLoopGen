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
    float temp = 0.;
    int ix = 0;
    for (j = 0; j < lenX; j++) {
        int x_index = ix;
        int a_index = lda * i + j;
        temp += X[x_index] * A[a_index];
        ix += incX;
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
