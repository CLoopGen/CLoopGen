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
    for (i = 0; i < N; i++) {
        int base_idx = ldc * i;
        int diag_offset = 2 * (base_idx + i);
        float *c_ptr = (float *)C;

        c_ptr[diag_offset] *= beta;
        c_ptr[diag_offset + 1] = 0;

        if (beta == 0.0f) {
            for (j = i + 1; j < N; j++) {
                int offset = 2 * (base_idx + j);
                c_ptr[offset] = 0;
                c_ptr[offset + 1] = 0;
            }
        } else {
            for (j = i + 1; j < N; j++) {
                int offset = 2 * (base_idx + j);
                c_ptr[offset] *= beta;
                c_ptr[offset + 1] *= beta;
            }
        }
    }
}
