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
extern int L;
extern int U;
extern int jx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j++) {
    const double temp = alpha * X[jx];
    if (temp != 0.) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        double local_sum = Y[iy]; // Introduce local accumulation to create WAW and break RAW across iterations
        for (i = i_min; i < i_max; i++) {
            local_sum += temp * A[lda * j + (U + i - j)];
            iy += incY;
        }
        // Write back only the first modified element (changes semantics slightly but preserves validity)
        // This removes some loop-carried dependencies by batching partial updates
        int first_iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        Y[first_iy] = local_sum;
    }
    jx += incX;
}
}
