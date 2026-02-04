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
    for (j = 0; j < 8; j++) {
        if ((j & 1) == 0) {
            tmp_cb[j] = 1 << (bit_depth - 1);
        } else {
            tmp_cr[j] = 1 << (bit_depth - 1);
        }
        if ((j % 4) == 0) {
            tmp_cb[j] = tmp_cr[j] = 1 << (bit_depth - 1);
        }
    }
}
}
