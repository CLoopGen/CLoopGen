#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    for (i = 0; i < N; i++) {
        int index_Aki = 2 * (k * lda + i);
        int index_Bki = 2 * (k * ldb + i);
        float Aki_real = ((const float *)A)[index_Aki];
        float Aki_imag = ((const float *)A)[index_Aki + 1];
        float Bki_real = ((const float *)B)[index_Bki];
        float Bki_imag = ((const float *)B)[index_Bki + 1];
        float temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        float temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
        for (j = 0; j <= i; j++) {
            int index_Akj = 2 * (k * lda + j);
            int index_Bkj = 2 * (k * ldb + j);
            int index_Cij = 2 * (i * lda + j);
            float Akj_real = ((const float *)A)[index_Akj];
            float Akj_imag = ((const float *)A)[index_Akj + 1];
            float Bkj_real = ((const float *)B)[index_Bkj];
            float Bkj_imag = ((const float *)B)[index_Bkj + 1];
            ((float *)C)[index_Cij] += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
            ((float *)C)[index_Cij + 1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
        }
    }
}
}
