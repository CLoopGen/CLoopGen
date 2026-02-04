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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int alpha_code = alpha_indices[x + y * 4];
        uint32_t pixel;
        uint8_t alpha = 0;

        if (!(alpha_code == 0 || alpha_code == 1)) {
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
        } else {
            alpha = (alpha_code == 0) ? alpha0 : alpha1;
        }

        pixel = colors[code & 3] | ((unsigned int)alpha << 24);
        code >>= 2;
        ((((union unaligned_32 *)(dst + x * 4))->l) = (pixel));
    }
    dst += stride;
}
}
