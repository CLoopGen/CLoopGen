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
        float local_alpha_real = alpha_real;
        float local_alpha_imag = alpha_imag;
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j);
            float Bij_real = B_float[idx];
            float Bij_imag = B_float[idx + 1];
            // Introduce artificial dependency: scale real part first and use it to perturb imaginary update
            float scaled_real = local_alpha_real * Bij_real;
            float scaled_imag = local_alpha_real * Bij_imag;
            // Modified update with introduced RAW dependency via scaled_real influencing both components
            B_float[idx] = scaled_real - local_alpha_imag * Bij_imag;
            B_float[idx + 1] = scaled_imag + local_alpha_imag * Bij_real + (scaled_real * 0.001f); // Artificial WAW-like chain via small coupling
        }
    }
}
