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
uint8_t alpha_values_flat[16];
uint32_t pixels[16];

int idx = 0;
for (y = 0; y < 4; y++) {
    const uint16_t alpha_code = (((const union unaligned_16 *)(block + 2 * y))->l);
    alpha_values_flat[idx+0] = ((alpha_code >> 0) & 15) * 17;
    alpha_values_flat[idx+1] = ((alpha_code >> 4) & 15) * 17;
    alpha_values_flat[idx+2] = ((alpha_code >> 8) & 15) * 17;
    alpha_values_flat[idx+3] = ((alpha_code >> 12) & 15) * 17;
    idx += 4;
}

idx = 0;
uint32_t temp_code = code;
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        uint8_t alpha = alpha_values_flat[idx];
        pixels[idx] = colors[temp_code & 3] | ((unsigned int)alpha << 24);
        temp_code >>= 2;
        idx++;
    }
}

idx = 0;
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        ((((union unaligned_32 *)(dst + x * 4))->l) = (pixels[idx]));
        idx++;
    }
    dst += stride;
}
}
