#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *x_base = X;
for (i = 0; i < N; i++) {
    ptrdiff_t offset_x = ix * sizeof(double);
    const double tmp = alpha * ((double*)x_base)[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j <= i; j++) {
        ptrdiff_t a_offset = (lda * i + j) * sizeof(double);
        ((double*)A)[(a_offset)/sizeof(double)] += ((double*)x_base)[jx] * tmp;
        jx += incX;
    }
    ix += incX;
}
}
