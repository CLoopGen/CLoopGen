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
    for (i = 0; i < 16; i++) {
        pixels += line_size;
        block += line_size;

        if (i >= 4) {
            (*(uint32_t *)(block - line_size)) = ((((const union unaligned_32 *)(pixels - line_size))->l));
            (*(uint32_t *)(block - line_size + 4)) = ((((const union unaligned_32 *)(pixels - line_size + 4))->l));
            (*(uint32_t *)(block - line_size + 8)) = ((((const union unaligned_32 *)(pixels - line_size + 8))->l));
            (*(uint32_t *)(block - line_size + 12)) = ((((const union unaligned_32 *)(pixels - line_size + 12))->l));
        }
    }

    // Handle first iteration separately to maintain correctness
    if (16 > 0) {
        (*(uint32_t *)(block - 16 * line_size)) = ((((const union unaligned_32 *)(pixels - 16 * line_size))->l));
        (*(uint32_t *)(block - 16 * line_size + 4)) = ((((const union unaligned_32 *)(pixels - 16 * line_size + 4))->l));
        (*(uint32_t *)(block - 16 * line_size + 8)) = ((((const union unaligned_32 *)(pixels - 16 * line_size + 8))->l));
        (*(uint32_t *)(block - 16 * line_size + 12)) = ((((const union unaligned_32 *)(pixels - 16 * line_size + 12))->l));
    }
}
