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
        uint8_t byte_c = (uint8_t)c;
        if (mono && (byte_c != 0)) {
            dst[x * pix_size + y * stride + offset] = byte_c;
        } else if (!mono) {
            uint32_t pixel = (byte_c | (byte_c << 8) | (byte_c << 16) | (0xFFU << 24));
            ((((union unaligned_32 *)(dst + x * pix_size + y * stride))->l) = pixel);
        }
    }
}
}
