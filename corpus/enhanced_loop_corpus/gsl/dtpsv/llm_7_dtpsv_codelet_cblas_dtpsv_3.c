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
    double *local_X = (double*)malloc(N * sizeof(double));
    if (!local_X) return;
    for (int k = 0; k < N; k++) {
        local_X[k] = X[k * incX];
    }
    for (i = N - 1; i >= 0; i--) {
        double tmp = local_X[i];
        for (j = i + 1; j < N; j++) {
            const double Aji = Ap[(((j) * ((j) + 1)) / 2 + (i))];
            tmp -= Aji * local_X[j];
        }
        if (nonunit) {
            local_X[i] = tmp / Ap[(((i) * ((i) + 1)) / 2 + (i))];
        } else {
            local_X[i] = tmp;
        }
    }
    for (int k = 0; k < N; k++) {
        X[k * incX] = local_X[k];
    }
    free(local_X);
}
