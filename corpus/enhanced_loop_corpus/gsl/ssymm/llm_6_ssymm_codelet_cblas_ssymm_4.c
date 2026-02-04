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
    for (j = 0; j < n2; j++) {
        const float temp1 = alpha * B[ldb * i + j];
        float temp2 = 0.;
        // Introduce temporary array to break WAW and WAR dependencies
        float *restrict local_C = &C[i * ldc];
        const float *restrict local_A = &A[j * lda];
        const float *restrict local_B = &B[ldb * i];
        
        // Update C[j] early with partial result
        local_C[j] += temp1 * local_A[j];
        
        for (k = j + 1; k < n2; k++) {
            const float Ajk = local_A[k];
            // Remove RAW dependency on C by reordering independent updates
            temp2 += local_B[k] * Ajk;
            local_C[k] += temp1 * Ajk;  // Independent write, no loop-carried dep
        }
        // Final update to C[j] includes accumulated temp2 — preserves semantics
        local_C[j] += alpha * temp2;
    }
}
}
