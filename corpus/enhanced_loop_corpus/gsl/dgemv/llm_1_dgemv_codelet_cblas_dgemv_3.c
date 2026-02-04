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
    const double alpha_val = alpha;
    if (alpha_val == 0.0 || lenX == 0 || lenY == 0) return;
    for (j = 0; j < lenX; j++) {
        const double temp = alpha_val * X[ix];
        ix += incX;
        if (temp != 0.0) {
            int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY));
            for (i = 0; i < lenY; i++) {
                Y[iy] += temp * A[j * lda + i];
                iy += incY;
            }
        }
    }
    ix -= incX; // Compensate extra increment from last iteration
}
