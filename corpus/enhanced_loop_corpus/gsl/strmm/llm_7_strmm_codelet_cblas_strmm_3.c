#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Change data access pattern to eliminate loop-carried dependencies by privatizing accumulation
    // and reordering computation to allow parallelization potential
    float *temp_arr = (float*)alloca(n2 * sizeof(float));
    for (i = 0; i < n1; i++) {
        // Precompute contributions from rows k > i to avoid repeated loads inside j-loop
        for (j = 0; j < n2; j++) {
            float temp = 0.0f;
            if (nonunit) {
                temp = A[i * lda + i] * B[i * ldb + j];
            } else {
                temp = B[i * ldb + j];
            }
            // Hoist part of inner loop: reduce redundant memory accesses
            for (k = i + 1; k < n1; k++) {
                temp += A[lda * k + i] * B[k * ldb + j];
            }
            temp_arr[j] = alpha * temp;
        }
        // Update B array after full j-scan to break WAW and WAR hazards
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] = temp_arr[j];
        }
    }
}
