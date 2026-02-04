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
        const float temp1 = alpha * B[j * ldb + i]; // Strided access: transpose indexing for B
        float temp2 = 0.;
        C[j * ldc + i] += temp1 * A[i * lda + i];   // Transposed write to C
        for (k = i + 1; k < n1; k++) {
            const float Aik = A[i * lda + k];
            C[j * ldc + k] += Aik * temp1;           // Update C with transposed layout
            temp2 += Aik * B[j * ldb + k];          // Consistently strided access in B and A
        }
        C[j * ldc + i] += alpha * temp2;
    }
}
}
