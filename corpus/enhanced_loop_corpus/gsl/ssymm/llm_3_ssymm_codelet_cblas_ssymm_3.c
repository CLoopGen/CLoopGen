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
for (j = 0; j < n2; j += 2) {  // Process two j columns at a time for improved spatial locality
    for (i = 0; i < n1; i++) {
        const float temp1_j0 = alpha * B[ldb * i + j];
        const float temp1_j1 = (j + 1 < n2) ? alpha * B[ldb * i + j + 1] : 0.0f;
        float temp2_j0 = 0.0f, temp2_j1 = 0.0f;
        for (k = 0; k < i; k++) {
            const float Aik = A[i * lda + k];
            // Update both C[k][j] and C[k][j+1] consecutively to improve memory locality
            float *C_col_j = &C[k * ldc + j];
            C_col_j[0] += Aik * temp1_j0;
            if (j + 1 < n2) C_col_j[1] += Aik * temp1_j1;

            temp2_j0 += Aik * B[ldb * k + j];
            if (j + 1 < n2) temp2_j1 += Aik * B[ldb * k + j + 1];
        }
        C[i * ldc + j] += temp1_j0 * A[i * lda + i] + alpha * temp2_j0;
        if (j + 1 < n2) {
            C[i * ldc + j + 1] += temp1_j1 * A[i * lda + i] + alpha * temp2_j1;
        }
    }
}
}
