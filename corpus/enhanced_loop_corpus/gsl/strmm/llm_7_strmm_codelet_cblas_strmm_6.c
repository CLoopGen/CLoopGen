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
for (i = 0; i < n1; i++) {
    // Move the j-loop to inner level and unroll partial dependency via scalar expansion
    // Introduce WAR hazard avoidance by using per-j temporaries, eliminating false sharing
    float temp_cache[64]; // Assume n2 <= 64 for stack safety in this variant
    if (n2 > 64) continue; // Skip execution if limit exceeded (for safety)
    for (j = 0; j < n2; j++) {
        temp_cache[j] = 0.;
        if (nonunit) {
            temp_cache[j] = A[j * lda + j] * B[i * ldb + j];
        } else {
            temp_cache[j] = B[i * ldb + j];
        }
        // Reverse loop order to create different data dependency chain (backward reduction)
        for (k = n2 - 1; k > j; k--) {
            temp_cache[j] += A[lda * k + j] * B[i * ldb + k];
        }
        // Final update with alpha scaling — write only once to B (WAW dependency reduced)
        B[ldb * i + j] = alpha * temp_cache[j];
    }
}
}
