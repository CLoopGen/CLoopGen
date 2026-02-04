#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *C_ptr = (float *)C;
    int idx;
    for (i = 0; i < N; i++) {
        idx = 2 * (ldc * i + i);
        C_ptr[idx] *= beta;
        C_ptr[idx + 1] = 0;
        for (j = i + 1; j < N; j++) {
            idx = 2 * (ldc * i + j);
            float temp_real = C_ptr[idx] * beta;
            float temp_imag = C_ptr[idx + 1] * beta;
            C_ptr[idx] = temp_real;
            C_ptr[idx + 1] = temp_imag;
        }
    }
}
