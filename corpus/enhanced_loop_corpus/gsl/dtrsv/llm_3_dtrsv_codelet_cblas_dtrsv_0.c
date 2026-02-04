#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop bounds and direct index arithmetic
    ptrdiff_t baseX = (ptrdiff_t)(X);
    for (i = 0; i < N - 1; i++) {
        int row = N - 2 - i;
        double tmp = *((double*)(baseX + (ix - i * incX)));
        int jx_offset = incX;
        for (j = row + 1; j < N; j++) {
            const double Aij = A[lda * row + j];
            tmp -= Aij * *((double*)(baseX + (ix - i * incX + jx_offset)));
            jx_offset += incX;
        }
        if (nonunit) {
            *((double*)(baseX + (ix - i * incX))) = tmp / A[lda * row + row];
        } else {
            *((double*)(baseX + (ix - i * incX))) = tmp;
        }
    }
}
