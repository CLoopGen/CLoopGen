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
// Reduce computational intensity and modify trip count by unrolling and adjusting inner loop frequency
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        if (i < N) { // Safe bound check for potential unroll
            const float Cij_real = (((float *)C)[2 * (ldc * i + j)]);
            const float Cij_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
            (((float *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real;
            (((float *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag;
        }
        if (i + 1 < N && (j >= i + 1)) {
            const float Cij_real = (((float *)C)[2 * (ldc * (i+1) + j)]);
            const float Cij_imag = (((float *)C)[2 * (ldc * (i+1) + j) + 1]);
            (((float *)C)[2 * (ldc * (i+1) + j)]) = beta_real * Cij_real;
            (((float *)C)[2 * (ldc * (i+1) + j) + 1]) = beta_real * Cij_imag;
        }
    }
}
}
