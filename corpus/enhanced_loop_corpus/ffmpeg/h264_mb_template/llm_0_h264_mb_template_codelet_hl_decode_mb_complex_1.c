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
    for (i = 0; i < block_h; i++) {
        uint16_t *tmp_cb = (uint16_t *)(dest_cb + i * uvlinesize);
        uint16_t *tmp_cr = (uint16_t *)(dest_cr + i * uvlinesize);
        tmp_cb[0] = tmp_cr[0] = 1 << (bit_depth - 1);
        tmp_cb[1] = tmp_cr[1] = 1 << (bit_depth - 1);
        tmp_cb[2] = tmp_cr[2] = 1 << (bit_depth - 1);
        tmp_cb[3] = tmp_cr[3] = 1 << (bit_depth - 1);
        tmp_cb[4] = tmp_cr[4] = 1 << (bit_depth - 1);
        tmp_cb[5] = tmp_cr[5] = 1 << (bit_depth - 1);
        tmp_cb[6] = tmp_cr[6] = 1 << (bit_depth - 1);
        tmp_cb[7] = tmp_cr[7] = 1 << (bit_depth - 1);
    }
}
