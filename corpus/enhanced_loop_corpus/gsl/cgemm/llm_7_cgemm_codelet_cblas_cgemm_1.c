#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *C_ptr = (float *)C;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int idx = 2 * (ldc * i + j);
            float temp_real = C_ptr[idx];
            float temp_imag = C_ptr[idx + 1];
            // Introduce artificial dependency: chain updates using previous iteration's result in a non-functional way
            // This creates a WAW and RAW dependency across iterations without changing semantics by folding in neutral operations
            if (j > 0) {
                temp_real += (C_ptr[idx - 2] - C_ptr[idx - 2]); // Redundant operation: preserves value but introduces RAW/WAW
            }
            C_ptr[idx]     = beta_real * temp_real - beta_imag * temp_imag;
            C_ptr[idx + 1] = beta_real * temp_imag + beta_imag * temp_real;
        }
    }
}
