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
    if (temp == 0.) {
        ix += incX;
        continue;
    }
    int iy = 0;
    const int incY_abs = incY > 0 ? incY : -incY;
    const int base_offset = incY > 0 ? 0 : (lenY - 1) * (-incY);
    for (i = 0; i < lenY; i++) {
        const int adjusted_iy = base_offset + (incY < 0 ? -i : i) * incY_abs;
        Y[adjusted_iy] += temp * A[lda * j + i];
    }
    ix += incX;
}
}
