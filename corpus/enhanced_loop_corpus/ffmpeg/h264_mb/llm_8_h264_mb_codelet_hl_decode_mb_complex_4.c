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
    int shift_val = bit_depth - 1;
    uint16_t init_val = 1 << shift_val;
    for (j = 0; j < 16; j += 2) {
        tmp_cb[j] = init_val;
        tmp_cb[j+1] = init_val;
        tmp_cr[j] = init_val;
        tmp_cr[j+1] = init_val;
    }
}
}
