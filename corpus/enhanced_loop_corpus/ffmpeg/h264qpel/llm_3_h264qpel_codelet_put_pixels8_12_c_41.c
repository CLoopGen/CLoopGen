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
    // Variant 2: Strided memory access - process every second row in each direction
    int i;
    uint8_t *p = pixels;
    uint8_t *b = block;
    ptrdiff_t step = 2 * line_size;
    int half_h = (h + 1) / 2;  // Ceiling of h/2 to cover all rows

    for (i = 0; i < half_h; i++) {
        // Forward strided access: even-indexed rows
        *((uint64_t *)b) = ((const union unaligned_64 *)(p))->l;
        *((uint64_t *)(b + 4 * sizeof(uint16_t))) = ((const union unaligned_64 *)(p + 4 * sizeof(uint16_t)))->l;

        p += step;
        b += step;
    }

    // Reset pointers to process odd-indexed rows
    p = pixels + line_size;
    b = block + line_size;

    for (i = 0; i < h / 2; i++) {
        // Strided access for odd rows
        *((uint64_t *)b) = ((const union unaligned_64 *)(p))->l;
        *((uint64_t *)(b + 4 * sizeof(uint16_t))) = ((const union unaligned_64 *)(p + 4 * sizeof(uint16_t)))->l;

        p += step;
        b += step;
    }
}
