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
    // Variant 2: Strided memory access — process every other row first, then the odd-indexed rows
    // This creates a strided access pattern over the pixel and block arrays
    int i;
    // First pass: even indices (0, 2, 4, ...)
    for (i = 0; i < h; i += 2) {
        *((uint64_t *)block) = ((const union unaligned_64 *)(pixels))->l;
        pixels += 2 * line_size;
        block += 2 * line_size;
    }
    // Reset pointers to process odd indices (1, 3, 5, ...)
    pixels -= h * line_size;  // Go back to start
    block -= h * line_size;
    if (h > 0) {
        pixels += line_size;
        block += line_size;
    }
    for (i = 1; i < h; i += 2) {
        *((uint64_t *)block) = ((const union unaligned_64 *)(pixels))->l;
        pixels += 2 * line_size;
        block += 2 * line_size;
    }
    // Adjust back to correct final position: after processing all rows
    if (h > 0) {
        pixels += (h % 2 == 0 ? 0 : -line_size); // If h is odd, we overshot reset
        block += (h % 2 == 0 ? 0 : -line_size);
    }
}
