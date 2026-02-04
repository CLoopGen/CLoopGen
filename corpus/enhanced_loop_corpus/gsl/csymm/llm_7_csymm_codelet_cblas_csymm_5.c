#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: remove inner loop and simplify updates
// This variant reduces arithmetic operations significantly by eliminating the k-loop
// and only updating the diagonal term directly.

for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;

        // Skip the entire k-loop: no triangular accumulation
        // Only update diagonal element C(i,j) using A(j,j), without any summation
        const float Ajj_real = (((const float *)A)[2 * (j * lda + j)]);
        const float Ajj_imag = (((const float *)A)[2 * (j * lda + j) + 1]);

        (((float *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;

        // Remove contribution from temp2 (alpha * sum_{k<j} B(i,k)*A(j,k)) — now zero
        // So we skip the final two lines that added alpha*temp2
    }
}
}
