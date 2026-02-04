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
    int j;
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            out[i] = block_size * (in[i] % n_blocks) + (in[i] / n_blocks);
            out[i+1] = block_size * (in[i+1] % n_blocks) + (in[i+1] / n_blocks);
        } else {
            out[i] = block_size * (in[i] % n_blocks) + (in[i] / n_blocks);
        }
    }
}
