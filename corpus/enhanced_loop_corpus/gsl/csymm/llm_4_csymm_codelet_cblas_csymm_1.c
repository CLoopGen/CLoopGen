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
        for (j = 0; j < n2; j++) {
            const int index = 2 * (ldc * i + j);
            const float Cij_real = ((float *)C)[index];
            const float Cij_imag = ((float *)C)[index + 1];

            // Introduce control dependency: only scale if either component is non-zero
            if (Cij_real != 0.0f || Cij_imag != 0.0f) {
                ((float *)C)[index]     = beta_real * Cij_real - beta_imag * Cij_imag;
                ((float *)C)[index + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
            }
            // Otherwise, leave unchanged (identity operation implied)
        }
    }
}
