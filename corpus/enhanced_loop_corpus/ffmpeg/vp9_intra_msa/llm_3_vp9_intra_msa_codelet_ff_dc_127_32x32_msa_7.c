#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **access_table = (uint8_t **)malloc(32 * sizeof(uint8_t *));
    if (!access_table) return;
    uint8_t *cur = dst;
    for (row = 0; row < 32; row++) {
        access_table[row] = cur;
        cur += dst_stride;
    }
    for (row = 16; row--;) {
        dst = access_table[2 * (15 - row)];
        dst = access_table[2 * (15 - row) + 1];
    }
    free(access_table);
}
