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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second row, then fill in the gaps (simulated striding)
    uint8_t *p = pixels;
    uint8_t *b = block;
    // Process even-indexed rows first (0,2,4,6), then odd (1,3,5,7) using stride of 2*line_size
    for (i = 0; i < 4; i++) {
        (*(uint32_t *)(b)) = ((((const union unaligned_32 *)(p))->l));
        (*(uint32_t *)(b + 4)) = ((((const union unaligned_32 *)(p + 4))->l));
        p += 2 * line_size;
        b += 2 * line_size;
    }
    // Reset to odd rows
    p = pixels + line_size;
    b = block + line_size;
    for (i = 0; i < 4; i++) {
        (*(uint32_t *)(b)) = ((((const union unaligned_32 *)(p))->l));
        (*(uint32_t *)(b + 4)) = ((((const union unaligned_32 *)(p + 4))->l));
        p += 2 * line_size;
        b += 2 * line_size;
    }
}
