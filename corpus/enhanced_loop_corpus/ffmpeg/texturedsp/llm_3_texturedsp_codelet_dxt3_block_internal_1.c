#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern uint32_t colors[4];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    const uint16_t alpha_code = (((const union unaligned_16 *)(block + 2 * y))->l);
    uint8_t alpha_values[4];
    alpha_values[0] = ((alpha_code >> 0) & 15) * 17;
    alpha_values[1] = ((alpha_code >> 4) & 15) * 17;
    alpha_values[2] = ((alpha_code >> 8) & 15) * 17;
    alpha_values[3] = ((alpha_code >> 12) & 15) * 17;
    uint8_t indices[4] = {0, 1, 2, 3};
    for (x = 0; x < 4; x++) {
        int idx = indices[x]; 
        uint8_t alpha = alpha_values[idx];
        uint32_t pixel = colors[code & 3] | ((unsigned int)alpha << 24);
        code >>= 2;
        ((((union unaligned_32 *)(dst + idx * 4))->l) = (pixel));
    }
    dst += stride;
}
}
