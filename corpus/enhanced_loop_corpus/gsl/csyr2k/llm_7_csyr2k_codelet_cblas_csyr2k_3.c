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
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        const int index = 2 * (ldc * i + j);
        float *Cptr = &((float *)C)[index];
        const float Cij_real = Cptr[0];
        const float Cij_imag = Cptr[1];
        Cptr[0] = beta_real * Cij_real - beta_imag * Cij_imag;
        Cptr[1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
    // Introduce artificial loop-carried dependency via redundant update on diagonal
    if (i > 0) {
        const int prev_diag_index = 2 * (ldc * (i-1) + (i-1));
        ((float *)C)[prev_diag_index] += ((float *)C)[prev_diag_index + 0] * 0.0f; // Redundant WAW-like pattern (no real effect but creates artificial dependence)
    }
}
}
