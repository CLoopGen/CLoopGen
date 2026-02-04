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
for (i = 0; i < 8; i++) {
    (*(uint32_t *)(block)) = ((((const union unaligned_32 *)(pixels))->l));
    (*(uint32_t *)(block + 4)) = ((((const union unaligned_32 *)(pixels + 4))->l));
    (*(uint32_t *)(block + 8)) = ((((const union unaligned_32 *)(pixels + 8))->l));
    (*(uint32_t *)(block + 12)) = ((((const union unaligned_32 *)(pixels + 12))->l));
    (*(uint32_t *)(block + line_size)) = ((((const union unaligned_32 *)(pixels + line_size))->l));
    (*(uint32_t *)(block + line_size + 4)) = ((((const union unaligned_32 *)(pixels + line_size + 4))->l));
    (*(uint32_t *)(block + line_size + 8)) = ((((const union unaligned_32 *)(pixels + line_size + 8))->l));
    (*(uint32_t *)(block + line_size + 12)) = ((((const union unaligned_32 *)(pixels + line_size + 12))->l));
    pixels += 2 * line_size;
    block += 2 * line_size;
}
}
