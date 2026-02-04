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
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        // Introduce artificial loop-carried dependence via delayed update to expose WAW-like pattern
        // Use a running sum with non-atomic but ordered updates to simulate stronger dependency
        for (k = 0; k < K; k++) {
            const float Aik_real = (((const float *)A)[2 * (i * lda + k)]);
            const float Aik_imag = (((const float *)A)[2 * (i * lda + k) + 1]);
            const float Ajk_real = (((const float *)A)[2 * (j * lda + k)]);
            const float Ajk_imag = -(((const float *)A)[2 * (j * lda + k) + 1]);

            // Break original recurrence slightly by using temporary intermediates that depend on prior temp
            // This introduces a more serialized dependency chain (stronger RAW)
            float delta_real = Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            float delta_imag = Aik_real * Ajk_imag + Aik_imag * Ajk_real;

            // Artificially serialize accumulation: each step depends on previous temp values
            temp_real = temp_real + delta_real;
            temp_imag = temp_imag + delta_imag;
        }
        // Maintain original write, but now temp has stronger internal loop-carried dependency
        float c_real = (((float *)C)[2 * (i * ldc + j)]);
        float c_imag = (((float *)C)[2 * (i * ldc + j) + 1]);

        // Add output WAR-like dependency by ensuring C access order is preserved
        c_real += alpha * temp_real;
        c_imag += alpha * temp_imag;

        (((float *)C)[2 * (i * ldc + j)]) = c_real;
        (((float *)C)[2 * (i * ldc + j) + 1]) = c_imag;
    }
}
}
