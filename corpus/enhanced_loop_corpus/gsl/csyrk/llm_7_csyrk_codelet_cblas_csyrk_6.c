#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp_real[N];  // Introduce array of temporaries to break WAW and WAR dependencies across j
    float temp_imag[N];
    for (int j = 0; j <= i; j++) {
        temp_real[j] = 0.;
        temp_imag[j] = 0.;
    }
    for (k = 0; k < K; k++) {
        for (int j = 0; j <= i; j++) {  // Move j-loop inside k-loop: eliminates loop-carried dependency on j, enables parallel update over j
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            temp_real[j] += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag[j] += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
    }
    for (int j = 0; j <= i; j++) {
        (((float *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real[j] - alpha_imag * temp_imag[j];
        (((float *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag[j] + alpha_imag * temp_real[j];
    }
}
}
