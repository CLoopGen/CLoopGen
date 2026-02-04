#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern int conjF;
extern int conjG;
extern  float *F;
extern  float *G;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change data access pattern to introduce loop-carried dependence in j-dimension
// and reorder computation to accumulate along j first for different memory behavior
for (i = 0; i < n1; i++) {
    // Hoist k-loop outward to change loop-carried dependencies
    // This creates a loop-nest reversal effect with temporary storage
    float temp_C_real[64]; // Assuming stack size is sufficient; bound by n2 max of 64
    float temp_C_imag[64];
    const int j_bound = (n2 < 64) ? n2 : 64;
    for (int jj = 0; jj < j_bound; jj++) {
        temp_C_real[jj] = (((float *)C)[2 * (ldc * i + jj)]);
        temp_C_imag[jj] = (((float *)C)[2 * (ldc * i + jj) + 1]);
    }
    for (k = 0; k < K; k++) {
        for (j = 0; j < j_bound; j++) {
            const float Fik_real = (((const float *)F)[2 * (ldf * i + k)]);
            const float Fik_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
            const float Gjk_real = (((const float *)G)[2 * (ldg * j + k)]);
            const float Gjk_imag = conjG * (((const float *)G)[2 * (ldg * j + k) + 1]);
            const float prod_real = Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            const float prod_imag = Fik_real * Gjk_imag + Fik_imag * Gjk_real;
            // Accumulate into temporary storage — introduces WAR/WAW dependencies across k
            temp_C_real[j] += alpha_real * prod_real - alpha_imag * prod_imag;
            temp_C_imag[j] += alpha_real * prod_imag + alpha_imag * prod_real;
        }
    }
    // Write back results to C
    for (j = 0; j < j_bound; j++) {
        (((float *)C)[2 * (ldc * i + j)]) = temp_C_real[j];
        (((float *)C)[2 * (ldc * i + j) + 1]) = temp_C_imag[j];
    }
    // Handle remaining j values beyond 64 if needed (rare, but safe)
    for (j = 64; j < n2; j++) {
        float temp_real = 0.;
        float temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const float Fik_real = (((const float *)F)[2 * (ldf * i + k)]);
            const float Fik_imag = conjF * (((const float *)F)[2 * (ldf * i + k) + 1]);
            const float Gjk_real = (((const float *)G)[2 * (ldg * j + k)]);
            const float Gjk_imag = conjG * (((const float *)G)[2 * (ldg * j + k) + 1]);
            temp_real += Fik_real * Gjk_real - Fik_imag * Gjk_imag;
            temp_imag += Fik_real * Gjk_imag + Fik_imag * Gjk_real;
        }
        (((float *)C)[2 * (ldc * i + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((float *)C)[2 * (ldc * i + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
