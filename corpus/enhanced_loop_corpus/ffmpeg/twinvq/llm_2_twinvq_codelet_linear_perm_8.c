#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *in;
extern int n_blocks;
extern int size;
extern int block_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride equal to block_size
    int stride = block_size > 0 ? block_size : 1;
    int limit = size / stride;
    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        out[idx] = block_size * (in[idx] % n_blocks) + in[idx] / n_blocks;
    }
}
