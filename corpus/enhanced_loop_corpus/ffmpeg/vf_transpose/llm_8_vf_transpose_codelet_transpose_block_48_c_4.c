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
for (y = 0; y < h; y++ , dst += dst_linesize , src += 6) {
    for (x = 0; x < w; x += 2) {
        int64_t v1 = (((uint64_t)((const uint8_t *)(src + x * src_linesize))[0] << 40) | 
                      ((uint64_t)((const uint8_t *)(src + x * src_linesize))[1] << 32) | 
                      ((uint64_t)((const uint8_t *)(src + x * src_linesize))[2] << 24) | 
                      ((uint64_t)((const uint8_t *)(src + x * src_linesize))[3] << 16) | 
                      ((uint64_t)((const uint8_t *)(src + x * src_linesize))[4] << 8) | 
                      (uint64_t)((const uint8_t *)(src + x * src_linesize))[5]);

        uint64_t d1 = v1;
        ((uint8_t *)(dst + 6 * x))[5] = d1;
        ((uint8_t *)(dst + 6 * x))[4] = d1 >> 8;
        ((uint8_t *)(dst + 6 * x))[3] = d1 >> 16;
        ((uint8_t *)(dst + 6 * x))[2] = d1 >> 24;
        ((uint8_t *)(dst + 6 * x))[1] = d1 >> 32;
        ((uint8_t *)(dst + 6 * x))[0] = d1 >> 40;

        if (x + 1 < w) {
            int64_t v2 = (((uint64_t)((const uint8_t *)(src + (x+1) * src_linesize))[0] << 40) | 
                          ((uint64_t)((const uint8_t *)(src + (x+1) * src_linesize))[1] << 32) | 
                          ((uint64_t)((const uint8_t *)(src + (x+1) * src_linesize))[2] << 24) | 
                          ((uint64_t)((const uint8_t *)(src + (x+1) * src_linesize))[3] << 16) | 
                          ((uint64_t)((const uint8_t *)(src + (x+1) * src_linesize))[4] << 8) | 
                          (uint64_t)((const uint8_t *)(src + (x+1) * src_linesize))[5]);

            uint64_t d2 = v2;
            ((uint8_t *)(dst + 6 * (x+1)))[5] = d2;
            ((uint8_t *)(dst + 6 * (x+1)))[4] = d2 >> 8;
            ((uint8_t *)(dst + 6 * (x+1)))[3] = d2 >> 16;
            ((uint8_t *)(dst + 6 * (x+1)))[2] = d2 >> 24;
            ((uint8_t *)(dst + 6 * (x+1)))[1] = d2 >> 32;
            ((uint8_t *)(dst + 6 * (x+1)))[0] = d2 >> 40;
        }
    }
}
}
