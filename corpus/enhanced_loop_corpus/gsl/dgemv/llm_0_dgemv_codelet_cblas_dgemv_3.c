#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (lenX <= 0 || lenY <= 0) return;
    const double alpha_val = alpha;
    int j_start = 0;
    int j_step = 1;
    int j_end = lenX;
    for (j = j_start; j < j_end; j += j_step) {
        const double temp = alpha_val * X[ix];
        if (temp != 0.) {
            int iy = 0;
            if (incY < 0) {
                iy = (lenY - 1) * (-incY);
            }
            for (i = 0; i < lenY; i++) {
                Y[iy] += temp * A[lda * j + i];
                iy += incY;
            }
        }
        ix += incX;
    }
}
