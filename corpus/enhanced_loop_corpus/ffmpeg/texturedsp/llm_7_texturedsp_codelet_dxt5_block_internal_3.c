#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern uint32_t colors[4];
extern uint8_t alpha_indices[16];
extern uint32_t code;
extern uint8_t alpha0;
extern uint8_t alpha1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint32_t local_colors[4]; // Remove potential aliasing-based RAW dependencies by caching colors
uint8_t local_alpha_indices[16];
ptrdiff_t local_stride = stride;
uint8_t *local_dst = dst;
uint32_t local_code = code;

// Preload data to eliminate repeated memory references and decouple from external mutation
for (int i = 0; i < 4; i++) local_colors[i] = colors[i];
for (int i = 0; i < 16; i++) local_alpha_indices[i] = alpha_indices[i];

for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int idx = x + y * 4;
        int alpha_code = local_alpha_indices[idx];
        uint8_t alpha;
        if (alpha_code == 0) {
            alpha = alpha0;
        } else if (alpha_code == 1) {
            alpha = alpha1;
        } else {
            if (alpha0 > alpha1) {
                alpha = (uint8_t)(((8 - alpha_code) * alpha0 + (alpha_code - 1) * alpha1) / 7);
            } else {
                if (alpha_code == 6) {
                    alpha = 0;
                } else if (alpha_code == 7) {
                    alpha = 255;
                } else {
                    alpha = (uint8_t)(((6 - alpha_code) * alpha0 + (alpha_code - 1) * alpha1) / 5);
                }
            }
        }
        uint32_t pixel = local_colors[local_code & 3] | ((unsigned int)alpha << 24);
        local_code >>= 2;
        ((((union unaligned_32 *)(local_dst + x * 4))->l) = (pixel));
    }
    local_dst += local_stride;
}
// Update shared state only at the end to introduce delayed write-back, eliminating intra-loop WAR/WAW hazards
dst = local_dst;
code = local_code;
}
