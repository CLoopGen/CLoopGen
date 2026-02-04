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
    for (i = 0; i < n1; i++) {
        // Modify control flow: skip entire row if index exceeds a dynamic bound
        if (i >= (n1 >> 1)) continue;

        for (j = 0; j < n2; j++) {
            const int offset = ldc * i + j;
            const int base_index = 2 * offset;

            const float Cij_real = ((float *)C)[base_index];
            const float Cij_imag = ((float *)C)[base_index + 1];

            // Apply transformation unconditionally
            ((float *)C)[base_index]     = beta_real * Cij_real - beta_imag * Cij_imag;
            ((float *)C)[base_index + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
