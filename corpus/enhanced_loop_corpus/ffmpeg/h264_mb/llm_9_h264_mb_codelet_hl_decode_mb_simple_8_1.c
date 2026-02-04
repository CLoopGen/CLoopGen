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
int stride = uvlinesize / sizeof(uint16_t);
for (i = 0; i < block_h; i++) {
    uint16_t *base_cb = (uint16_t *)dest_cb + i * stride;
    uint16_t *base_cr = (uint16_t *)dest_cr + i * stride;
    uint16_t mid_val = 1 << (bit_depth - 1);
    for (j = 0; j < 16; j += 2) {
        base_cb[j]     = mid_val;
        base_cb[j + 1] = mid_val;
        base_cr[j]     = mid_val;
        base_cr[j + 1] = mid_val;
    }
}
}
