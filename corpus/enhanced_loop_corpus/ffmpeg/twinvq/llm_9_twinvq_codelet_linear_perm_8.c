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
    int temp_mod, temp_div;
    for (i = 0; i < size; i++) {
        temp_mod = in[i] % n_blocks;
        temp_div = in[i] / n_blocks;
        out[i] = block_size * temp_mod;
        out[i] += temp_div;
    }
}
