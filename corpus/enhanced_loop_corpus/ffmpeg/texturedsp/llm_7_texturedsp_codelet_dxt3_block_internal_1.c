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
uint32_t local_colors[4]; // Remove RAW dependency on global 'colors' by caching early
for (int i = 0; i < 4; i++) {
    local_colors[i] = colors[i];
}
uint32_t temp_code = code; // Break loop-carried dependency on 'code' by using local accumulator
for (y = 0; y < 4; y++) {
    const uint16_t alpha_code = (((const union unaligned_16 *)(block + 2 * y))->l);
    // Reorder and fuse computation: compute all alphas and pixels before store
    uint32_t pixels[4];
    uint8_t a0 = ((alpha_code >> 0) & 15) * 17;
    uint8_t a1 = ((alpha_code >> 4) & 15) * 17;
    uint8_t a2 = ((alpha_code >> 8) & 15) * 17;
    uint8_t a3 = ((alpha_code >> 12) & 15) * 17;
    pixels[0] = local_colors[temp_code & 3] | ((unsigned int)a0 << 24); temp_code >>= 2;
    pixels[1] = local_colors[temp_code & 3] | ((unsigned int)a1 << 24); temp_code >>= 2;
    pixels[2] = local_colors[temp_code & 3] | ((unsigned int)a2 << 24); temp_code >>= 2;
    pixels[3] = local_colors[temp_code & 3] | ((unsigned int)a3 << 24); temp_code >>= 2;
    // Store all pixels in reverse order to modify access pattern (WAR-like effect avoided via local buffer)
    for (x = 3; x >= 0; x--) {
        ((((union unaligned_32 *)(dst + x * 4))->l) = (pixels[x]));
    }
    dst += stride;
}
code = temp_code; // Commit final code state after loop
}
