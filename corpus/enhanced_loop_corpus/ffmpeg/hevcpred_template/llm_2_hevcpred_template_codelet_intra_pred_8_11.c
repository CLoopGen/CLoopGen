#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int size_max_y;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual unrolling for better spatial locality
    int limit = size_max_y - (size_max_y % 4);
    for (i = 0; i < limit; i += 4) {
        uint8_t *addr = left + i;
        ((union unaligned_32 *)(addr + 0))->l = pix;
    }
    // Handle remaining elements if any
    for (; i < size_max_y; i += 4) {
        ((union unaligned_32 *)(left + i))->l = pix;
    }
}
