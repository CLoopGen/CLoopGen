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
    // Reverse loop order on j to change loop-carried dependency direction (introduce backward dependence)
    for (j = n2 - 1; j >= 0; j--) {
        const float temp1 = alpha * B[ldb * i + j];
        float temp2 = 0.;
        // Eliminate some WAW hazards by deferring updates to C via local accumulation
        for (k = 0; k < j; k++) {
            const float Ajk = A[j * lda + k];
            // Update C earlier but with different scheduling — introduces WAR if not handled
            C[i * ldc + k] = C[i * ldc + k] + temp1 * Ajk; // RAW on C, but no loop-carried dep
            temp2 += B[ldb * i + k] * Ajk;
        }
        // Break original loop-carried flow by using independent temp storage
        temp2_accum += temp2; // Artificially create cumulative dependency across j
        C[i * ldc + j] = C[i * ldc + j] + temp1 * A[j * lda + j] + alpha * temp2;
    }
    // Dummy use of accumulated value to prevent dead code elimination
    if (n2 > 0) {
        C[i * ldc] += temp2_accum * 0.f; // No-op math to preserve dependency without side effect
    }
}
}
