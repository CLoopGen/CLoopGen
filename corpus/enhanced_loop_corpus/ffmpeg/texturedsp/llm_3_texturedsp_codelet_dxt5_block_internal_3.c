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
    // Variant 2: Indirect memory access using index mapping array for non-linear traversal
    static const int index_map[16] = {0, 5, 10, 15, 1, 4, 11, 14, 2, 7, 8, 13, 3, 6, 9, 12}; // Zigzag-like access pattern
    uint8_t temp_dst[64]; // Local buffer to decouple store timing and enable reordering
    ptrdiff_t offsets[16];

    // Precompute write offsets based on stride and indirect indexing
    for (int i = 0; i < 16; i++) {
        int mapped_idx = index_map[i];
        int iy = mapped_idx / 4;
        int ix = mapped_idx % 4;
        offsets[i] = iy * stride + ix * 4;
    }

    // Process in indirect order but compute alpha and color as needed
    for (int i = 0; i < 16; i++) {
        int mapped_idx = index_map[i];
        int alpha_code = alpha_indices[mapped_idx];
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
        uint32_t pixel = colors[code & 3] | ((unsigned int)alpha << 24);
        code >>= 2;

        // Store into temporary linear buffer using direct indexing
        *(uint32_t*)&temp_dst[i * 4] = pixel;
    }

    // Apply the precomputed offset map to write to final destination
    for (int i = 0; i < 16; i++) {
        *(uint32_t*)(dst + offsets[i]) = *(uint32_t*)&temp_dst[i * 4];
    }
}
