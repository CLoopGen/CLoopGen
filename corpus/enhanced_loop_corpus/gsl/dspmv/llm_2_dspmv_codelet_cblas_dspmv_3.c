#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *Ap;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    double tmp1 = alpha * X[ix];
    double tmp2 = 0.;
    const int j_min = 0;
    const int j_max = i;
    int base_idx_A = (i * (i + 1)) / 2;
    Y[iy] += tmp1 * Ap[base_idx_A + i];
    for (j = j_min; j < j_max; j++) {
        const double apk = Ap[base_idx_A + j];
        Y[j * incY] += tmp1 * apk;
        tmp2 += apk * X[j * incX];
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
