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
    int i, j;
    for (i = 0; i < size; i++) {
        out[i] = 0;
        for (j = 0; j < block_size; j++) {
            if (j == (in[i] % n_blocks)) {
                out[i] += j;
            }
        }
        out[i] = out[i] + (in[i] / n_blocks);
    }
}
