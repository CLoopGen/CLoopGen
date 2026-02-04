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
    int base_offset, inner_idx;
    for (i = 0; i < N; i++) {
        base_offset = 2 * ldc * i;
        // Update diagonal element with no dependency on prior writes in same iteration
        inner_idx = base_offset + 2 * i;
        C_ptr[inner_idx] *= beta;
        C_ptr[inner_idx + 1] = 0;

        // Introduce temporary accumulation to create artificial RAW dependency
        float accum_real = 0.0f, accum_imag = 0.0f;
        for (j = i + 1; j < N; j++) {
            inner_idx = base_offset + 2 * j;
            // Artificially chain computations via accumulators (introduces intra-loop RAW)
            accum_real += C_ptr[inner_idx];
            accum_imag += C_ptr[inner_idx + 1];
            C_ptr[inner_idx] = accum_real * beta;
            C_ptr[inner_idx + 1] = accum_imag * beta;
        }
    }
}
