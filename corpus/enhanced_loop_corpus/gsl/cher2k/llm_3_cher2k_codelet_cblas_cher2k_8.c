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
extern float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use strided memory access with precomputed stride offsets
    // Precompute index strides for A, B, and C to simulate a more cache-friendly or transformed layout
    int A_stride = 2 * lda;
    int B_stride = 2 * ldb;
    int C_stride = 2 * lda;

    for (k = 0; k < K; k++) {
        int base_Ak = 2 * k * lda;
        int base_Bk = 2 * k * ldb;
        for (i = 0; i < N; i++) {
            int idx_Aki = base_Ak + 2 * i;
            int idx_Bki = base_Bk + 2 * i;
            float Aki_real = ((const float *)A)[idx_Aki];
            float Aki_imag = ((const float *)A)[idx_Aki + 1];
            float Bki_real = ((const float *)B)[idx_Bki];
            float Bki_imag = ((const float *)B)[idx_Bki + 1];
            float temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            float temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            float temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            float temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);

            int base_Ci = i * C_stride;
            for (j = 0; j < i; j++) {
                int idx_Akj = base_Ak + 2 * j;
                int idx_Bkj = base_Bk + 2 * j;
                float Akj_real = ((const float *)A)[idx_Akj];
                float Akj_imag = ((const float *)A)[idx_Akj + 1];
                float Bkj_real = ((const float *)B)[idx_Bkj];
                float Bkj_imag = ((const float *)B)[idx_Bkj + 1];
                int idx_Cij = base_Ci + 2 * j;
                ((float *)C)[idx_Cij]     += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) +
                                             (temp2_real * Akj_real - temp2_imag * Akj_imag);
                ((float *)C)[idx_Cij + 1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) +
                                             (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            int idx_Cii = base_Ci + 2 * i;
            ((float *)C)[idx_Cii]     += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            ((float *)C)[idx_Cii + 1] = 0.0f;
        }
    }
}
