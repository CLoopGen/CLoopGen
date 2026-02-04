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
    const int j_min = i + 1;
    const int j_max = N;

    // Change memory access to use unit-stride for inner loop by precomputing base pointers
    double *ap_base = &Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) - (i))];
    double *x_ptr = &X[ix + incX];  // Start from X[i+1] equivalent
    double *y_ptr = &Y[iy + incY];  // Start from Y[i+1] equivalent

    Y[iy] += tmp1 * ap_base[i];

    for (j = j_min; j < j_max; j++) {
        const double apk = ap_base[j];
        y_ptr[(j - j_min) * incY] += tmp1 * apk;
        tmp2 += apk * x_ptr[(j - j_min) * incX];
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
