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
    int base_a = lda * i;
    int ix_start = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
    for (j = 0; j < lenX; j++) {
        int a_offset = base_a + j;
        int x_offset = ix_start + j * incX;
        temp += X[x_offset] * A[a_offset];
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
