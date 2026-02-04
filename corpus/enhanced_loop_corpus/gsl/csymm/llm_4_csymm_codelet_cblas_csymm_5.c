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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        const float Bij_real = (((const float *)B)[2 * (ldb * i + j)]);
        const float Bij_imag = (((const float *)B)[2 * (ldb * i + j) + 1]);
        const float temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        float temp2_real = 0.;
        float temp2_imag = 0.;
        // Introduce a forward-carried dependency by reordering computation
        // and accumulating into a temporary that depends on prior k iterations.
        for (k = 0; k < j; k++) {
            const float Ajk_real = (((const float *)A)[2 * (lda * j + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (lda * j + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (ldb * i + k)]);
            const float Bik_imag = (((const float *)B)[2 * (ldb * i + k) + 1]);
            // Move C update to after inner accumulation to break WAW hazard early
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        // Now perform all writes to C in a batch, removing write-after-write hazards
        // from repeated updates inside the k-loop. This changes data dependency pattern.
        for (k = 0; k < j; k++) {
            const float Ajk_real = (((const float *)A)[2 * (lda * j + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (lda * j + k) + 1]);
            (((float *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((float *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
        }
        {
            const float Ajj_real = (((const float *)A)[2 * (lda * j + j)]);
            const float Ajj_imag = (((const float *)A)[2 * (lda * j + j) + 1]);
            (((float *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            (((float *)C)[2 * (i * ldc + j) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;
        }
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
