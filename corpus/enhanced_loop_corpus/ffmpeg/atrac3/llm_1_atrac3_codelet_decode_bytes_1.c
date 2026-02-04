#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i_block;
    int remainder = (bytes / 4) % 4;
    int block_count = (bytes / 4) / 4;

    for (i_block = 0; i_block < block_count; i_block++) {
        int base_idx = i_block * 4;
        output[base_idx]     = c ^ buf[base_idx];
        output[base_idx + 1] = c ^ buf[base_idx + 1];
        output[base_idx + 2] = c ^ buf[base_idx + 2];
        output[base_idx + 3] = c ^ buf[base_idx + 3];
    }

    for (i = block_count * 4; i < bytes / 4; i++) {
        output[i] = c ^ buf[i];
    }
}
