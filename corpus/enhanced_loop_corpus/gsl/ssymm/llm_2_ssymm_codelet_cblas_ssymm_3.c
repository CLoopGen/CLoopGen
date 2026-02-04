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
        const float temp1 = alpha * B[j * ldb + i];  // Transposed access: B[j][i] instead of B[i][j]
        float temp2 = 0.;
        for (k = 0; k < i; k++) {
            const float Aik = A[k * lda + i];  // Access A[k][i] instead of A[i][k], transposed read
            C[j * ldc + k] += Aik * temp1;     // Update C[j][k], column-major update pattern
            temp2 += Aik * B[j * ldb + k];     // B[j][k] with transposed indexing
        }
        C[j * ldc + i] += temp1 * A[i * lda + i] + alpha * temp2;  // Final update with modified access
    }
}
}
