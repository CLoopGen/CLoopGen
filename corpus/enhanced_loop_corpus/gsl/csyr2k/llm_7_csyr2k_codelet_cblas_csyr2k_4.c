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
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float temp_real = 0.0f;
        float temp_imag = 0.0f;
        // Introduce artificial loop-carried dependence by unrolling with state carry
        int k = 0;
        // Unroll by factor of 2 with chained dependency
        if (K > 0) {
            // Initialize with first element
            const float Aik_real_init = (((const float *)A)[2 * (i * lda + 0)]);
            const float Aik_imag_init = (((const float *)A)[2 * (i * lda + 0) + 1]);
            const float Bik_real_init = (((const float *)B)[2 * (i * ldb + 0)]);
            const float Bik_imag_init = (((const float *)B)[2 * (i * ldb + 0) + 1]);
            const float Ajk_real_init = (((const float *)A)[2 * (j * lda + 0)]);
            const float Ajk_imag_init = (((const float *)A)[2 * (j * lda + 0) + 1]);
            const float Bjk_real_init = (((const float *)B)[2 * (j * ldb + 0)]);
            const float Bjk_imag_init = (((const float *)B)[2 * (j * ldb + 0) + 1]);
            temp_real = (Aik_real_init * Bjk_real_init - Aik_imag_init * Bjk_imag_init) +
                        (Bik_real_init * Ajk_real_init - Bik_imag_init * Ajk_imag_init);
            temp_imag = (Aik_real_init * Bjk_imag_init + Aik_imag_init * Bjk_real_init) +
                        (Bik_real_init * Ajk_imag_init + Bik_imag_init * Ajk_real_init);
            k = 1;
        }
        for (; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Bik_real = (((const float *)B)[2 * (i * ldb + k)]);
            const float Bik_imag = (((const float *)B)[2 * (i * ldb + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = (((const float *)A)[2 * (j * lda + k) + 1]);
            const float Bjk_real = (((const float *)B)[2 * (j * ldb + k)]);
            const float Bjk_imag = (((const float *)B)[2 * (j * ldb + k) + 1]);
            // Create WAW and RAW dependency: current temp depends strictly on previous
            float delta_real = (Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
            float delta_imag = (Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real);
            temp_real += delta_real;
            temp_imag += delta_imag;
        }
        // Final update to C with accumulated values
        float Cres = (((float *)C)[2 * (i * ldc + j)]);
        float Cims = (((float *)C)[2 * (i * ldc + j) + 1]);
        Cres += alpha_real * temp_real - alpha_imag * temp_imag;
        Cims += alpha_real * temp_imag + alpha_imag * temp_real;
        (((float *)C)[2 * (i * ldc + j)]) = Cres;
        (((float *)C)[2 * (i * ldc + j) + 1]) = Cims;
    }
}
}
