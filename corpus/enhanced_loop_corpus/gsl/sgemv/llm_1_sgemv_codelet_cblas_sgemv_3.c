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
if (lenX <= 0 || lenY <= 0) return;
const float temp_scalar = alpha;
int base_ix = ix;
for (j = 0; j < lenX; j++) {
    const float temp = temp_scalar * X[base_ix];
    base_ix += incX;
    if (temp != 0.) {
        int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY));
        for (i = 0; i < lenY; i++) {
            for (int k = 0; k < 1; k++) {  // Artificially increased nesting depth
                Y[iy] += temp * A[lda * j + i];
            }
            iy += incY;
        }
    }
}
}
