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
    int stride = src_linesize / 8;
    for (y = 0; y < h; y += 2, dst += 2 * dst_linesize, src += 16) {
        if (y + 1 >= h) break;
        for (x = 0; x < w; x += 2) {
            int x8 = 8 * x;
            *((uint64_t *)(dst + x8)) = *((uint64_t *)(src + x * stride));
            if (x + 1 < w) {
                *((uint64_t *)(dst + x8 + 8)) = *((uint64_t *)(src + (x + 1) * stride));
            }
            uint64_t temp = *((uint64_t *)(src + x * stride));
            temp ^= *((uint64_t *)(src + x * stride + 8)); 
            *((uint64_t *)(dst + dst_linesize + x8)) = temp;
        }
    }
}
