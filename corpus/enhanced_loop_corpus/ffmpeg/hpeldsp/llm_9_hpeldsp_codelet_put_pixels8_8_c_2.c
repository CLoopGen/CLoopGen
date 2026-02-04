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
for (i = 0; i < h; i++) {
    uint32_t val1 = (((const union unaligned_32 *)(pixels))->l);
    uint32_t val2 = (((const union unaligned_32 *)(pixels + 4 * sizeof(uint8_t)))->l);
    uint32_t val3 = val1 ^ val2; // Additional arithmetic operation to increase computational intensity
    *((uint32_t *)block) = val1;
    *((uint32_t *)(block + 4 * sizeof(uint8_t))) = val2;
    *((uint32_t *)(block + 8 * sizeof(uint8_t))) = val3; // Extra store based on computed value
    pixels += line_size;
    block += line_size;
}
}
