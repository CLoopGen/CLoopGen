#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int base_ix = (incX > 0 ? 0 : (N - 1) * (-incX));
for (i = 0; i < N; i++) {
    int ax_start = lda * i;
    int x_index = base_ix + i * incX;
    double temp = (nonunit ? A[ax_start] : 1.0) * X[x_index];
    const int j_end = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    for (j = i + 1; j < j_end; j++) {
        int aj_offset = j - i;
        int xj_index = base_ix + j * incX;
        temp += X[xj_index] * A[ax_start + aj_offset];
    }
    X[x_index] = temp;
}
}
