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
    // Variant 2: Strided memory access - process every second row (strided by 2*line_size), then handle remaining if needed
    uint8_t *p = pixels;
    uint8_t *b = block;
    int i;
    int step = 2;
    // Process even-indexed rows first with stride
    for (i = 0; i < h; i += step) {
        const union unaligned_32 *px = (const union unaligned_32 *)(p);
        ((union unaligned_32 *)b)->l = px->l;
        // Skip next row in both source and destination
        p += 2 * line_size;
        b += 2 * line_size;
    }
    // Handle odd row if h is odd
    if (h % 2 == 1) {
        const union unaligned_32 *px = (const union unaligned_32 *)(pixels + (h - 1) * line_size);
        ((union unaligned_32 *)(block + (h - 1) * line_size))->l = px->l;
    }
}
