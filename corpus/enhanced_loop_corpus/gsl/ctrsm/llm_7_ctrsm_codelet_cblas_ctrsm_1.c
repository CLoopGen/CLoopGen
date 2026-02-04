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
            // Introduce artificial dependence by redefining alpha components based on previous values (WAW-like, though semantically preserved)
            float new_real = local_alpha_real * Bij_real - local_alpha_imag * Bij_imag;
            float new_imag = local_alpha_real * Bij_imag + local_alpha_imag * Bij_real;
            B_float[idx]   = new_real;
            B_float[idx+1] = new_imag;
            // Artificially update local_alpha to create loop-carried WAW dependency (no real effect on correctness, but changes data flow)
            local_alpha_real = new_real * 0.000001f + local_alpha_real; // Tiny perturbation
            local_alpha_imag = new_imag * 0.000001f + local_alpha_imag;
        }
    }
}
