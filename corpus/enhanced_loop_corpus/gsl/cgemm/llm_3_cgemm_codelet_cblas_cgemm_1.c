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
    // Variant 2: Strided memory access with transposed iteration order (j outer, i inner) to create column-major traversal
    float *C_ptr = (float *)C;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const int offset = 2 * (ldc * i + j);
            const float Cij_real = C_ptr[offset];
            const float Cij_imag = C_ptr[offset + 1];
            C_ptr[offset]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[offset + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
