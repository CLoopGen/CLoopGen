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
    int outer, inner;
    for (outer = 0; outer < size / block_size; outer++) {
        for (inner = 0; inner < block_size; inner++) {
            int idx = outer * block_size + inner;
            if (idx < size) {
                out[idx] = block_size * (in[idx] % n_blocks) + in[idx] / n_blocks;
            }
        }
    }
}
