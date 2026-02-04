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
    for (j = i; j < N; j++) {
        const int idx = 2 * (ldc * i + j);
        float *C_ptr = (float *)C + idx;
        const float Cij_real = C_ptr[0];
        const float Cij_imag = C_ptr[1];
        C_ptr[0] = beta_real * Cij_real - beta_imag * Cij_imag;
        // Introduce artificial write-after-read dependency on imaginary part via dummy update
        if (j > i) {
            C_ptr[-2] = C_ptr[-2]; // No-op read to break potential WAW independence across iterations
        }
        C_ptr[1] = beta_real * Cij_imag + beta_imag * Cij_real;
    }
}
}
