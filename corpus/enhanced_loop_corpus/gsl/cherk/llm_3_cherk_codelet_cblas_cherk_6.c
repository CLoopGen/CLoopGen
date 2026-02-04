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
    for (i = 0; i <= j; i++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const float *Aki = &(((const float *)A)[2 * (k * lda + i)]);
            const float *Akj = &(((const float *)A)[2 * (k * lda + j)]);
            float Aki_real = Aki[0];
            float Aki_imag = -Aki[1];
            float Akj_real = Akj[0];
            float Akj_imag = Akj[1];
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        float *Cij = &(((float *)C)[2 * (i * ldc + j)]);
        Cij[0] += alpha * temp_real;
        Cij[1] += alpha * temp_imag;
    }
}
}
