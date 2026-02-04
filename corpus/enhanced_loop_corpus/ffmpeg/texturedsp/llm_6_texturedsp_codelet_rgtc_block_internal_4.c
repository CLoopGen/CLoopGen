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
    int temp_buffer[16]; // Local buffer to accumulate results and break direct store dependencies
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int i = indices[x + y * 4];
            int c = color_tab[i];
            int idx = x + y * 4;
            temp_buffer[idx] = c; // Store computed color early, decoupling load from later store
        }
    }
    // Second pass: write out results using accumulated data
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int idx = x + y * 4;
            int c = temp_buffer[idx];
            if (mono) {
                dst[x * pix_size + y * stride + offset] = (uint8_t)c;
            } else {
                uint32_t pixel = (((uint8_t)(c) << 0) | ((uint8_t)(c) << 8) | ((uint8_t)(c) << 16) | ((unsigned int)(uint8_t)(255U) << 24));
                ((((union unaligned_32 *)(dst + x * pix_size + y * stride))->l) = (pixel));
            }
        }
    }
}
