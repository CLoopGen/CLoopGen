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
for (y = 0; y < h; y += 2, dst += 2 * dst_linesize, src += 8) {
    for (x = 0; x < w; x++)
        *((uint32_t *)(dst + 4 * x)) = *((uint32_t *)(src + x * src_linesize));
    if (y + 1 < h) {
        uint8_t *dst_next = dst + dst_linesize;
        uint8_t *src_next = src + 4;
        for (x = 0; x < w; x++)
            *((uint32_t *)(dst_next + 4 * x)) = *((uint32_t *)(src_next + x * src_linesize));
    }
}
}
