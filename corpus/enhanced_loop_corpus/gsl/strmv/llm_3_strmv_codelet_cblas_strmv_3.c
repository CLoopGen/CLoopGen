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
const int base_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
for (i = 0; i < N; i++) {
    float temp = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int index_x = base_ix + (i + 1) * incX;
    int index_a = lda * (i + 1) + i;
    for (j = j_min; j < j_max; j++) {
        temp += X[index_x] * A[index_a];
        index_x += incX;
        index_a += lda;
    }
    int result_index = base_ix + i * incX;
    if (nonunit) {
        X[result_index] = temp + X[result_index] * A[lda * i + i];
    } else {
        X[result_index] += temp;
    }
}
}
