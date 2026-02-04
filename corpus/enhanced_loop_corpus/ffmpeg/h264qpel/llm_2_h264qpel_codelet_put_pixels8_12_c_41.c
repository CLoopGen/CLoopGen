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
    // Variant 1: Consecutive memory access with loop unrolling by 2
    int i;
    uint8_t *p = pixels;
    uint8_t *b = block;
    for (i = 0; i < h - 1; i += 2) {
        *((uint64_t *)b) = ((const union unaligned_64 *)(p))->l;
        *((uint64_t *)(b + 4 * sizeof(uint16_t))) = ((const union unaligned_64 *)(p + 4 * sizeof(uint16_t)))->l;

        *((uint64_t *)(b + line_size)) = ((const union unaligned_64 *)(p + line_size))->l;
        *((uint64_t *)(b + line_size + 4 * sizeof(uint16_t))) = ((const union unaligned_64 *)(p + line_size + 4 * sizeof(uint16_t)))->l;

        p += 2 * line_size;
        b += 2 * line_size;
    }
    // Handle remaining iteration if h is odd
    if (i < h) {
        *((uint64_t *)b) = ((const union unaligned_64 *)(p))->l;
        *((uint64_t *)(b + 4 * sizeof(uint16_t))) = ((const union unaligned_64 *)(p + 4 * sizeof(uint16_t)))->l;
    }
}
