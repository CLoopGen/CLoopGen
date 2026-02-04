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
for (i = 0; i < block_h * 4; i += 4) {
    uint16_t *base_cb = (uint16_t *)dest_cb + i * stride;
    uint16_t *base_cr = (uint16_t *)dest_cr + i * stride;
    uint16_t val = 1 << (bit_depth - 1);
    for (j = 0; j < 8; j += 2) {
        base_cb[j]     = base_cr[j]     = val;
        base_cb[j + 1] = base_cr[j + 1] = val ^ 0xFF;
    }
    if (i + 1 < block_h) {
        uint16_t *next_cb = (uint16_t *)dest_cb + (i + 1) * stride;
        uint16_t *next_cr = (uint16_t *)dest_cr + (i + 1) * stride;
        for (j = 0; j < 4; j++) {
            next_cb[j] = next_cr[j] = val >> 1;
        }
    }
}
}
