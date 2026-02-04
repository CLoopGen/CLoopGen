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
    for (j = 0; j < n2; j++) {
        const float temp1 = alpha * B[ldb * i + j];
        float temp2 = 0.0f;
        for (k = 0; k < i; k++) {
            const float Aik = A[i * lda + k];
            // Modify data dependency: delay write to C by accumulating updates in temp2_accum per i, reducing WAW and RAW hazards across j
            C[k * ldc + j] = C[k * ldc + j] + Aik * temp1;  // Still RAW on C, but reordered
            temp2 += Aik * B[ldb * k + j];
        }
        temp2_accum += temp2; // Accumulate temp2 across j to create loop-carried dependency on temp2_accum
    }
    // Apply accumulated value outside inner j-loop to introduce loop-carried WAW on temp2_accum and change reduction scope
    C[i * ldc + 0] += alpha * temp2_accum; // Broadcast partial result to first column
}
}
