#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
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
const int stride = incX * (N - 1);
int* index_map = (int*)alloca(N * sizeof(int));
for (int idx = 0; idx < N; ++idx) {
    index_map[idx] = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + idx * incX;
}
for (i = 0; i < N; i++) {
    double temp = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    for (j = j_min; j < j_max; j++) {
        temp += X[index_map[j]] * A[lda * i + j];
    }
    if (nonunit) {
        X[index_map[i]] = temp + X[index_map[i]] * A[lda * i + i];
    } else {
        X[index_map[i]] += temp;
    }
}
}
