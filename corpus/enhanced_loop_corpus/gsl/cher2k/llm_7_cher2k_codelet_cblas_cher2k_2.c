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
float *c_ptr = (float *)C;
for (i = 0; i < N; i++) {
    int base_i = ldc * i;
    int idx_diag = 2 * (base_i + i);
    c_ptr[idx_diag] *= beta;
    c_ptr[idx_diag + 1] = 0.0f;
    for (j = i + 1; j < N; j++) {
        int idx_off = 2 * (base_i + j);
        c_ptr[idx_off] *= beta;
        c_ptr[idx_off + 1] *= beta;
    }
}
}
