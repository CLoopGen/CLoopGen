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
    (*(uint32_t *)(block)) = ((((const union unaligned_32 *)(pixels + 0))->l));
    (*(uint32_t *)(block + 1 * line_size)) = ((((const union unaligned_32 *)(pixels + 4))->l));
    (*(uint32_t *)(block + 2 * line_size)) = ((((const union unaligned_32 *)(pixels + 8))->l));
    (*(uint32_t *)(block + 3 * line_size)) = ((((const union unaligned_32 *)(pixels + 12))->l));
    pixels += 4;
    block += 4;
}
}
