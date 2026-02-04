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
for (j = 0; j < lenX; j += 2) {
    const double temp1 = alpha * X[jx];
    const double temp2 = (j + 1 < lenX) ? alpha * X[jx + incX] : 0.0;
    if (temp1 != 0. || temp2 != 0.) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        for (i = i_min; i < i_max; i++) {
            Y[iy] += temp1 * A[lda * j + (U + i - j)];
            if (temp2 != 0. && j + 1 < lenX) {
                const int offset = lda * (j + 1) + (U + i - (j + 1));
                Y[iy] += temp2 * A[offset];
            }
            iy += incY;
        }
    }
    jx += 2 * incX;
}
}
