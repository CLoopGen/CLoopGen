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
    // Variant 2: Reduced loop nesting depth by flattening the logic — eliminate the inner loop
    // and replace with direct unrolled iterations up to a fixed limit (e.g., small L+U range).
    // Here we assume L and U are small and bounded (e.g., <= 4), allowing partial unrolling.
    for (j = 0; j < lenX; j++) {
        const double temp = alpha * X[jx];
        if (temp != 0.) {
            const int i_min = (j > U ? j - U : 0);
            const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
            int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;

            // Unroll up to 5 iterations; remaining handled via sequential scalar updates
            int i = i_min;
            while (i + 4 < i_max) {
                Y[iy                  ] += temp * A[lda * j + (U + i              - j)]; iy += incY;
                Y[iy                  ] += temp * A[lda * j + (U + i + 1          - j)]; iy += incY;
                Y[iy                  ] += temp * A[lda * j + (U + i + 2          - j)]; iy += incY;
                Y[iy                  ] += temp * A[lda * j + (U + i + 3          - j)]; iy += incY;
                Y[iy                  ] += temp * A[lda * j + (U + i + 4          - j)]; iy += incY;
                i += 5;
            }
            // Handle remaining elements normally (but still as straight-line code)
            for (; i < i_max; i++) {
                Y[iy] += temp * A[lda * j + (U + i - j)];
                iy += incY;
            }
        }
        jx += incX;
    }
}
