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
const int strideX = abs(incX);
const int strideY = abs(incY);
double *X_base = X + (incX < 0 ? (N - 1) * (-incX) : 0);
double *Y_base = Y + (incY < 0 ? (N - 1) * (-incY) : 0);
int indices[N];
for (int idx = 0; idx < N; ++idx) {
    indices[idx] = idx;
}
for (i = 0; i < N; i++) {
    int rev_i = indices[N - 1 - i];
    double tmp1 = alpha * X_base[rev_i * strideX];
    double tmp2 = 0.;
    const int j_min = 0;
    const int j_max = rev_i;
    Y_base[rev_i * strideY] += tmp1 * Ap[((rev_i) * (rev_i + 1)) / 2 + rev_i];
    for (j = j_min; j < j_max; j++) {
        int rev_j = indices[j];
        const double apk = Ap[((rev_i) * (rev_i + 1)) / 2 + rev_j];
        Y_base[rev_j * strideY] += tmp1 * apk;
        tmp2 += apk * X_base[rev_j * strideX];
    }
    Y_base[rev_i * strideY] += alpha * tmp2;
}
ix = (incX < 0 ? 0 : (N - 1) * incX) + incX;
iy = (incY < 0 ? 0 : (N - 1) * incY) + incY;
}
