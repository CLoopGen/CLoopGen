#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float alpha;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        const float *base_A = (const float *)A;
        for (k = 0; k < K; k++) {
            int offset_i = 2 * (k * lda + i);
            int offset_j = 2 * (k * lda + j);
            float a_re = base_A[offset_i];
            float a_im = -base_A[offset_i + 1];
            float b_re = base_A[offset_j];
            float b_im = base_A[offset_j + 1];
            temp_real += a_re * b_re - a_im * b_im;
            temp_imag += a_re * b_im + a_im * b_re;
        }
        float *C_ptr = (float *)C;
        int c_index = 2 * (i * ldc + j);
        C_ptr[c_index] += alpha * temp_real;
        C_ptr[c_index + 1] += alpha * temp_imag;
    }
}
}
