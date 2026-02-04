#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern ptrdiff_t stride;
extern  int *color_tab;
extern int mono;
extern int offset;
extern int pix_size;
extern uint8_t indices[16];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_mono = mono; // Introduce local copy to create artificial dependency on loop-invariant
    ptrdiff_t local_stride = stride;
    int local_offset = offset;
    int local_pix_size = pix_size;
    uint8_t* local_dst = dst;
    // Process in reverse order to change memory access pattern and eliminate potential forward loop-carried dependencies
    for (y = 3; y >= 0; y--) {
        for (x = 3; x >= 0; x--) {
            int i = indices[x + y * 4];
            int c = color_tab[i];
            // Introduce artificial dependency: current iteration depends on previous (x,y) value via reuse of 'c'
            if (x > 0 || y > 0) {
                int prev_i = indices[(x > 0 ? x - 1 : 3) + (x > 0 ? y : y - 1) * 4];
                int prev_c = color_tab[prev_i];
                c ^= prev_c; // Add RAW-like dependency on prior iteration (artificial but valid)
            }
            if (local_mono) {
                local_dst[x * local_pix_size + y * local_stride + local_offset] = (uint8_t)(c & 0xFF);
            } else {
                uint32_t pixel = (((uint8_t)(c) << 0) | ((uint8_t)(c) << 8) | ((uint8_t)(c) << 16) | ((unsigned int)(uint8_t)(255U) << 24));
                ((((union unaligned_32 *)(local_dst + x * local_pix_size + y * local_stride))->l) = (pixel));
            }
        }
    }
}
