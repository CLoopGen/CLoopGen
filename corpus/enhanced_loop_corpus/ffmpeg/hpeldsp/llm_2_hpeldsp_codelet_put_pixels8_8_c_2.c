#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 iteration
    // Instead of accessing pixels in a strided pattern per original, we process two aligned 32-bit values consecutively
    // and step through the buffer with unit stride after unrolling.
    for (i = 0; i < h; i++) {
        uint8_t *p = pixels;
        uint8_t *b = block;
        // Load four bytes as a 32-bit word using union aliasing for unaligned access
        ((uint32_t*)b)[0] = ((const union unaligned_32*)(p + 0))->l;
        ((uint32_t*)b)[1] = ((const union unaligned_32*)(p + 4))->l;
        ((uint32_t*)b)[2] = ((const union unaligned_32*)(p + 8))->l;
        ((uint32_t*)b)[3] = ((const union unaligned_32*)(p + 12))->l;

        pixels += line_size;
        block += line_size;
    }
}
