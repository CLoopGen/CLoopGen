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
    // Variant 1: Consecutive Memory Access Pattern
    // Modify access to A and X to use consecutive indexing by precomputing base pointers
    // This improves spatial locality and may aid vectorization

    float *base_X = X;
    for (i = 0; i < N; i++) {
        int offset_A = lda * i;
        float temp = (nonunit ? A[offset_A] : 1.0f) * base_X[0];
        const int j_min = i + 1;
        const int j_max = (N < i + K + 1) ? N : (i + K + 1);
        float *curr_X = base_X + j_min;
        int a_index = j_min - i;
        for (j = j_min; j < j_max; j++) {
            temp += curr_X[0] * A[offset_A + a_index];
            curr_X++;
            a_index++;
        }
        base_X[0] = temp;
        base_X++;
    }
}
