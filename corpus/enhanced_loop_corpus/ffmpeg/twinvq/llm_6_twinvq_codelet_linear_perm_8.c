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
    int16_t temp;
    for (i = 0; i < size; i++) {
        temp = in[i] % n_blocks;
        out[i] = block_size * temp + in[i] / n_blocks;
    }
}
