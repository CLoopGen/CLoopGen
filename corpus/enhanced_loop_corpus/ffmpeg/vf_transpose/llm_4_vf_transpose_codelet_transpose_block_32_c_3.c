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
    if (w <= 0 || h <= 0) return;
    for (y = 0; y < h; y++) {
        uint8_t *src_row = src + y * src_linesize;
        uint8_t *dst_row = dst + y * dst_linesize;
        for (x = 0; x < w; x++) {
            if ((x + y) & 1) continue;
            *((uint32_t *)(dst_row + 4 * x)) = *((uint32_t *)(src_row + x * 4));
        }
    }
}
