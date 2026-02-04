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
    // Variant 1: Consecutive memory access with precomputed pixel values and flattened loop
    uint32_t pixels[16];
    int idx = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int alpha_code = alpha_indices[idx];
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
            pixels[idx] = colors[code & 3] | ((unsigned int)alpha << 24);
            code >>= 2;
            idx++;
        }
    }
    // Write pixels consecutively to destination with stride adjustment
    uint8_t* row = dst;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ((((union unaligned_32 *)(row + j * 4))->l) = (pixels[i * 4 + j]));
        }
        row += stride;
    }
}
