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
for (i = 0; i < N; i++) {
    float temp = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    // Change memory access pattern: use base pointer with scaled index (consecutive-like access via precomputed strides)
    int base_jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = j_min; j < j_max; j++) {
        int offset_x = base_jx + j * incX;
        int offset_a = lda * i + j;
        temp += X[offset_x] * A[offset_a];
    }
    int self_index = lda * i + i;
    int x_index = base_jx + i * incX;
    if (nonunit) {
        X[x_index] = temp + X[x_index] * A[self_index];
    } else {
        X[x_index] += temp;
    }
}
}
