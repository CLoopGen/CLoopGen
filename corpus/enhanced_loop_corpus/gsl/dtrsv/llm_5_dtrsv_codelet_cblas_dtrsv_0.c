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
    for (i = N - 1; i > 0 && i--;) {
        double tmp = X[ix];
        jx = ix + incX;
        int skip_update = 0;
        if (nonunit) {
            double diag = A[lda * i + i];
            if (diag == 0.0) {
                skip_update = 1;
            } else {
                for (j = i + 1; j < N; j++) {
                    const double Aij = A[lda * i + j];
                    tmp -= Aij * X[jx];
                    jx += incX;
                }
                X[ix] = tmp / diag;
            }
        } else {
            for (j = i + 1; j < N; j++) {
                const double Aij = A[lda * i + j];
                tmp -= Aij * X[jx];
                jx += incX;
            }
            X[ix] = tmp;
        }
        if (!skip_update) {
            ix -= incX;
        } else {
            ix -= incX;
        }
    }
}
