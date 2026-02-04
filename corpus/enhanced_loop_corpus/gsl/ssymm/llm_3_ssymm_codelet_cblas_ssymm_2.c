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
float * restrict base_A = A;
float * restrict base_B = B;
float * restrict base_C = C;
for (i = 0; i < n1; i++) {
    float * restrict row_A = base_A + i * lda;      // Base pointer for row i of A
    float * restrict col_B = base_B + i;            // Stride by 1, assuming column-major offset for B
    float * restrict col_C = base_C + i;            // Column i in C, assuming column-major storage
    for (j = 0; j < n2; j++) {
        const float temp1 = alpha * col_B[ldb * j]; // Consecutive access along column i of B
        float temp2 = 0.;
        col_C[ldc * j] += temp1 * row_A[i];         // Self-element from A
        for (k = i + 1; k < n1; k++) {
            const float Aik = row_A[k];              // Direct row access in A
            float * restrict dst_C = base_C + k + j * ldc;
            *dst_C += Aik * temp1;                   // Scatter update to C[k][j]
            temp2 += Aik * (base_B[k + ldb * j]);    // Indirect but predictable access in B
        }
        col_C[ldc * j] += alpha * temp2;
    }
}
}
