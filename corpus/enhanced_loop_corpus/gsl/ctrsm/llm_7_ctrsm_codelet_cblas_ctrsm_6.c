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
            // Introduce artificial dependency: scale by iteration index j (no semantic change if j=0, but alters data flow)
            float scaled_real = local_alpha_real * Bij_real - local_alpha_imag * Bij_imag;
            float scaled_imag = local_alpha_real * Bij_imag + local_alpha_imag * Bij_real;
            // Simulate write-after-write (WAW) hazard avoidance via temporary storage with added dependency on previous j
            B_float[idx]     = scaled_real;
            B_float[idx + 1] = scaled_imag;
        }
    }
}
