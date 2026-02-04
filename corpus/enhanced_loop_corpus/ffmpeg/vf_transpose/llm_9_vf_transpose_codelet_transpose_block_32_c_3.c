#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t src_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++ , dst += dst_linesize , src += 4) {
    uint32_t *dst32 = (uint32_t *)dst;
    const uint32_t *src32 = (const uint32_t *)src;
    for (x = 0; x < w; x += 4) {
        dst32[x + 0] = src32[x + 0];
        dst32[x + 1] = src32[x + 1];
        dst32[x + 2] = src32[x + 2];
        dst32[x + 3] = src32[x + 3];
    }
}
}
