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
for (i = 0; i < 32; i += 2) {
    uint32_t val1 = (((const union unaligned_32 *)(pixels))->l);
    uint32_t val2 = (((const union unaligned_32 *)(pixels + 4))->l);
    uint32_t val3 = (((const union unaligned_32 *)(pixels + 8))->l);
    uint32_t val4 = (((const union unaligned_32 *)(pixels + 12))->l);
    (*(uint32_t *)(block)) = val1 ^ 0xFFFFFFFFU;
    (*(uint32_t *)(block + 4)) = val2 ^ 0xFFFFFFFFU;
    (*(uint32_t *)(block + 8)) = val3 ^ 0xFFFFFFFFU;
    (*(uint32_t *)(block + 12)) = val4 ^ 0xFFFFFFFFU;
    pixels += line_size;
    block += line_size;

    val1 = (((const union unaligned_32 *)(pixels))->l);
    val2 = (((const union unaligned_32 *)(pixels + 4))->l);
    val3 = (((const union unaligned_32 *)(pixels + 8))->l);
    val4 = (((const union unaligned_32 *)(pixels + 12))->l);
    (*(uint32_t *)(block)) = val1 ^ 0xFFFFFFFFU;
    (*(uint32_t *)(block + 4)) = val2 ^ 0xFFFFFFFFU;
    (*(uint32_t *)(block + 8)) = val3 ^ 0xFFFFFFFFU;
    (*(uint32_t *)(block + 12)) = val4 ^ 0xFFFFFFFFU;
    pixels += line_size;
    block += line_size;
}
}
