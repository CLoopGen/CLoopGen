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
double *base_X = X;
ptrdiff_t *indices = (ptrdiff_t*)alloca(N * sizeof(ptrdiff_t));
for (int k = 0; k < N; k++) {
    indices[k] = (incX > 0 ? k * incX : (N - 1 - k) * (-incX));
}
for (i = N; i > 0 && i--;) {
    ptrdiff_t packed_idx = (i * (2 * N - i + 1)) / 2 - 1;
    double atmp = Ap[packed_idx];
    double temp = (nonunit ? base_X[indices[ix]] * atmp : base_X[indices[ix]]);
    for (j = 0; j < i; j++) {
        ptrdiff_t ap_index = ((j + 1) * (2 * N - j)) / 2 + (i - j - 1);
        atmp = Ap[ap_index];
        temp += atmp * base_X[indices[j]];
    }
    base_X[indices[ix]] = temp;
    ix -= incX;
}
}
