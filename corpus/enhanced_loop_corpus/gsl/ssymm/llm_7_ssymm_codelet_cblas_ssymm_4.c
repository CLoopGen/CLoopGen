#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *B;
extern  int ldb;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    float temp2_accum = 0.0f;
    // Reverse loop order to change data dependency traversal pattern
    for (j = n2 - 1; j >= 0; j--) {
        const float temp1 = alpha * B[ldb * i + j];
        float temp2 = 0.0f;
        
        // Move accumulation of temp2 to after the inner loop to create delayed use
        C[i * ldc + j] += temp1 * A[j * lda + j];
        
        for (k = j + 1; k < n2; k++) {
            const float Ajk = A[j * lda + k];
            // Reorder computation: delay usage of B[i][k] to eliminate early RAW
            C[i * ldc + k] += temp1 * Ajk;
        }
        
        // Compute temp2 in a separate pass to eliminate intra-loop dependency chain
        for (k = j + 1; k < n2; k++) {
            temp2 += B[ldb * i + k] * A[j * lda + k];
        }
        
        // Accumulate temp2 across j iterations to introduce artificial dependency
        temp2_accum += temp2;
        // Apply combined effect at end of row to modify data flow
        if (j == 0) {
            for (int m = 0; m < n2; m++) {
                C[i * ldc + m] += alpha * temp2_accum;
            }
        }
    }
}
}
