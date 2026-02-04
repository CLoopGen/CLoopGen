#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *B_float = (float *)B;
    for (i = 0; i < n1; i++) {
        int base_idx = ldb * i;
        float row_accum_real = 0.0f;
        float row_accum_imag = 0.0f;
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j);
            float Bij_real = B_float[idx];
            float Bij_imag = B_float[idx + 1];
            row_accum_real += Bij_real;
            row_accum_imag += Bij_imag;
            B_float[idx]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            B_float[idx + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
        // Introduce artificial dependency: use accumulated values (no functional impact on correctness)
        // This adds a loop-carried data dependency (WAW-like via accumulator) without changing semantics
        if (n2 > 0) {
            B_float[2 * base_idx]     += row_accum_real * 0.0f; // No-op, but introduces compiler-visible dependency
            B_float[2 * base_idx + 1] += row_accum_imag * 0.0f;
        }
    }
}
