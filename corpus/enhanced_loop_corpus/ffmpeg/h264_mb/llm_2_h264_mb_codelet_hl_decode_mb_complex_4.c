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
    // Variant 1: Consecutive memory access with pointer arithmetic (forward traversal)
    uint16_t value = 1 << (bit_depth - 1);
    for (i = 0; i < block_h; i++) {
        uint16_t *tmp_cb = (uint16_t *)(dest_cb + i * uvlinesize);
        uint16_t *tmp_cr = (uint16_t *)(dest_cr + i * uvlinesize);
        uint16_t *end_cb = tmp_cb + 8;
        while (tmp_cb < end_cb) {
            *(tmp_cb++) = value;
            *(tmp_cr++) = value;
        }
    }
}
