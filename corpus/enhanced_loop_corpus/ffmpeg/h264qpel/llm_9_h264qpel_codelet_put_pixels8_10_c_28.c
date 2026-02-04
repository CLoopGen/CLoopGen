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
for (i = 0; i < h; i++) {
    uint64_t val1 = (((const union unaligned_64 *)(pixels))->l);
    uint64_t val2 = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
    *((uint64_t *)block) = val1 ^ 0x8000800080008000ULL;
    *((uint64_t *)(block + 4 * sizeof(uint16_t))) = val2 ^ 0x8000800080008000ULL;
    pixels += line_size;
    block += line_size;
}
}
