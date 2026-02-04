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
    // Variant 2: Strided memory access – process every second row, stepping by 2 in height
    uint8_t *p = pixels;
    uint8_t *b = block;
    int i;
    for (i = 0; i < h; i += 2) {
        if (i + 1 >= h) break;
        *((uint64_t *)b) = (((const union unaligned_64 *)(p))->l);
        *((uint64_t *)(b + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(p + 4 * sizeof(uint16_t)))->l);

        *((uint64_t *)(b + line_size)) = (((const union unaligned_64 *)(p + line_size))->l);
        *((uint64_t *)(b + line_size + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(p + line_size + 4 * sizeof(uint16_t)))->l);

        p += 2 * line_size;
        b += 2 * line_size;
    }
}
