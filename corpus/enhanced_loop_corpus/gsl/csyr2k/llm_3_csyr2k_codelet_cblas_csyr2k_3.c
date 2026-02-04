#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed inner loop to simulate backward traversal (still row-major)
    float *C_base = (float *)C;
    for (i = 0; i < N; i++) {
        const int row_start = i;
        for (j = row_start; j >= 0; j--) {  // Reverse inner loop order: j from i down to 0
            const ptrdiff_t offset = 2 * (ldc * i + j);
            const float Cij_real = C_base[offset];
            const float Cij_imag = C_base[offset + 1];
            C_base[offset]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_base[offset + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
