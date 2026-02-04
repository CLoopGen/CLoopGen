#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest_cb;
extern uint8_t *dest_cr;
extern int uvlinesize;
extern int i;
extern  int block_h;
extern  int bit_depth;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total_iters = block_h * 4;
for (i = 0; i < total_iters; i++) {
    int row = (i * 2) / 8;
    int offset = (i * 2) % 8;
    if (row < block_h) {
        uint16_t *tmp_cb = (uint16_t *)(dest_cb + row * uvlinesize);
        uint16_t *tmp_cr = (uint16_t *)(dest_cr + row * uvlinesize);
        uint16_t val = (1 << (bit_depth - 1)) + (offset << 1);
        tmp_cb[offset] = val;
        tmp_cr[offset] = val ^ ((bit_depth > 8) ? 0x10 : 0x00);
    }
}
}
