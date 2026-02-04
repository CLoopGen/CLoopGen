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
    double temp_cache = 0.0;
    for (j = 0; j < lenX; j++) {
        temp_cache = alpha * X[ix];
        if (temp_cache != 0.) {
            int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
            double local_sum = 0.0;
            for (i = 0; i < lenY; i++) {
                local_sum += temp_cache * A[lda * j + i];
                Y[iy] += local_sum;  // Introduce WAW and RAW dependency: Y[iy] depends on previous updates
                iy += incY;
            }
        }
        ix += incX;
    }
}
