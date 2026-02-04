#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
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
    // Variant 2: Strided Memory Access with Index Array Simulation (Indirect-like Access)
    // Simulate indirect access via precomputed index array for X, while keeping A strided
    // Increases memory access flexibility and mimics indirect patterns without actual indirection arrays

    int *index_map = (int*)alloca(N * sizeof(int));
    for (int idx = 0; idx < N; idx++) {
        index_map[idx] = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + idx * incX;
    }

    for (i = 0; i < N; i++) {
        float temp = (nonunit ? A[lda * i + 0] : 1.0f) * X[index_map[i]];
        const int j_min = i + 1;
        const int j_max = (N < i + K + 1) ? N : (i + K + 1);
        for (j = j_min; j < j_max; j++) {
            temp += X[index_map[j]] * A[lda * i + (j - i)];
        }
        X[index_map[i]] = temp;
    }
}
