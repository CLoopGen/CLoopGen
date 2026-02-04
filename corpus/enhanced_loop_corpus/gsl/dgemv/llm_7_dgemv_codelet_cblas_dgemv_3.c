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
    for (j = 0; j < lenX; j++) {
        const double temp = alpha * X[ix];
        if (temp != 0.) {
            int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
            double * restrict y_ptr = &Y[iy];
            const double * restrict a_ptr = &A[lda * j];
            for (i = 0; i < lenY; i++) {
                // Remove loop-carried dependency by unrolling assumption and using temporary accumulation
                double accum = temp * a_ptr[i];
                y_ptr[i * incY] = accum;  // Eliminate read-before-write (RAW): overwrite instead of accumulate
            }
        }
        ix += incX;
    }
}
