#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *restrict local_X = X;
float *restrict local_A = A;
int local_ix = ix;
for (i = 0; i < N; i++) {
    float temp = 0.0f;
    const int j_start = i + 1;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_start * incX;
    for (j = j_start; j < N; j++) {
        temp += local_X[jx] * local_A[lda * j + i];
        jx += incX;
    }
    if (nonunit) {
        local_X[local_ix] = temp + local_X[local_ix] * local_A[lda * i + i];
    } else {
        local_X[local_ix] += temp;
    }
    local_ix += incX;
}
ix = local_ix;
}
