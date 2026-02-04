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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1, temp2;
    int ix1, ix2;
    int j_unroll;
    for (i = 0; i < lenY; i++) {
        temp1 = 0.0;
        temp2 = 0.0;
        ix1 = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
        ix2 = ix1 + incX;
        for (j = 0; j < lenX; j += 2) {
            j_unroll = j + 1;
            if (j_unroll < lenX) {
                temp1 += X[ix1] * A[lda * i + j];
                temp2 += X[ix2] * A[lda * i + j_unroll];
                ix1 += 2 * incX;
                ix2 += 2 * incX;
            } else {
                temp1 += X[ix1] * A[lda * i + j];
                break;
            }
        }
        temp1 += temp2;
        Y[iy] += alpha * temp1;
        iy += incY;
    }
}
