#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < N; i++) {
    double tmp = X[ix];
    int jx = (incX > 0) ? 0 : (N - 1) * (-incX);
    if (i > 0) {
        for (j = 0; j < i; j++) {
            int index = (((j + 1) * (2 * N - j)) / 2) + i - j - 1;
            const double Aji = Ap[index];
            tmp -= Aji * X[jx];
            jx += incX;
        }
        if (nonunit) {
            int diag_index = (((i + 1) * (2 * N - i)) / 2) - 1;
            double diag_val = Ap[diag_index];
            X[ix] = (diag_val != 0.0) ? tmp / diag_val : tmp;
        } else {
            X[ix] = tmp;
        }
    }
    ix += incX;
}
}
