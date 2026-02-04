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
    const float *Ap = (const float *)A + 2 * k * lda;
    const float *Bp = (const float *)B + 2 * k * ldb;
    for (i = 0; i < N; i++) {
        const float *Aki_ptr = Ap + 2 * i;
        const float *Bki_ptr = Bp + 2 * i;
        float Aki_real = Aki_ptr[0];
        float Aki_imag = Aki_ptr[1];
        float Bki_real = Bki_ptr[0];
        float Bki_imag = Bki_ptr[1];
        float temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        float temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        float temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
        for (j = 0; j <= i; j++) {
            const float *Akj_ptr = Ap + 2 * j;
            const float *Bkj_ptr = Bp + 2 * j;
            float Akj_real = Akj_ptr[0];
            float Akj_imag = Akj_ptr[1];
            float Bkj_real = Bkj_ptr[0];
            float Bkj_imag = Bkj_ptr[1];
            int index_Cij = 2 * (i * lda + j);
            ((float *)C)[index_Cij] += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
            ((float *)C)[index_Cij + 1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
        }
    }
}
}
