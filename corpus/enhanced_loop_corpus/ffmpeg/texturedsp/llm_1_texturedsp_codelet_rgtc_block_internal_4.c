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
int i = 0;
for (i = 0; i < 16; i++) {
    int x = i & 3;
    int y = i >> 2;
    int c = color_tab[indices[i]];
    if (mono) {
        dst[x * pix_size + y * stride + offset] = (uint8_t)c;
    } else {
        uint32_t pixel = ((uint8_t)c | ((uint8_t)c << 8) | ((uint8_t)c << 16) | (255U << 24));
        ((((union unaligned_32 *)(dst + x * pix_size + y * stride + offset))->l) = pixel);
    }
}
}
