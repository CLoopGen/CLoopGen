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
    for (i = 0; i < size; i++) {
        int16_t val = in[i];
        int16_t mod_val = val % n_blocks;
        int16_t div_val = val / n_blocks;
        if (mod_val >= 0) {
            out[i] = block_size * mod_val + div_val;
        } else {
            out[i] = block_size * (mod_val + n_blocks) + div_val;
        }
    }
}
