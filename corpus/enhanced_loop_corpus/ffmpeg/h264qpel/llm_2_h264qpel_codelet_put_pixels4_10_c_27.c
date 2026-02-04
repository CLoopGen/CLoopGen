#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual unrolling (factor of 2)
    // This variant assumes h is even for simplicity, and accesses pixels and block in consecutive pairs
    int i;
    for (i = 0; i < h - 1; i += 2) {
        *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
        *((uint64_t *)(block + line_size)) = (((const union unaligned_64 *)(pixels + line_size))->l);
        pixels += 2 * line_size;
        block += 2 * line_size;
    }
    // Handle remaining iteration if h is odd
    if (i < h) {
        *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
        pixels += line_size;
        block += line_size;
    }
}
