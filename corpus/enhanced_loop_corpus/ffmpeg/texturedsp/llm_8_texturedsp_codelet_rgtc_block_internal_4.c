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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int i = indices[x + y * 4];
        int c = color_tab[i];
        if (mono) {
            dst[x * pix_size + y * stride + offset] = (uint8_t)c;
        } else {
            uint32_t r = (uint8_t)(c);
            uint32_t g = (uint8_t)(c >> 8);
            uint32_t b = (uint8_t)(c >> 16);
            uint32_t a = 255U;
            uint32_t pixel = (r << 0) | (g << 8) | (b << 16) | (a << 24);
            ((((union unaligned_32 *)(dst + x * pix_size + y * stride))->l) = (pixel));
        }
    }
}
}
