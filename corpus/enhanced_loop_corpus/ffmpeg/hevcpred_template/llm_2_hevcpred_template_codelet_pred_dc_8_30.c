#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint8_t *src;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (transpose access pattern to row-major consecutive writes)
    // Instead of accessing with stride*i + j, we reorganize to write in blocks of 4 consecutively.
    for (i = 0; i < size; i++) {
        uint8_t *row_base = &src[stride * i];
        for (j = 0; j < size; j += 4) {
            ((union unaligned_32 *)(row_base + j))->l = a;
        }
    }
}
