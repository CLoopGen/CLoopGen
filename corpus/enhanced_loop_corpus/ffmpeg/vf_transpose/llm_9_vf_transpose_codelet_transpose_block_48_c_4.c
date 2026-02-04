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
for (y = 0; y < h; y += 2, dst += 2 * dst_linesize, src += 12) {
    if (y + 1 < h) {
        for (x = 0; x < w; x++) {
            int64_t v_curr = (((uint64_t)((const uint8_t *)(src + x * src_linesize))[0] << 40) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[1] << 32) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[2] << 24) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[3] << 16) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[4] << 8) | 
                              (uint64_t)((const uint8_t *)(src + x * src_linesize))[5]);

            uint64_t d_curr = v_curr;
            ((uint8_t *)(dst + 6 * x))[5] = d_curr;
            ((uint8_t *)(dst + 6 * x))[4] = d_curr >> 8;
            ((uint8_t *)(dst + 6 * x))[3] = d_curr >> 16;
            ((uint8_t *)(dst + 6 * x))[2] = d_curr >> 24;
            ((uint8_t *)(dst + 6 * x))[1] = d_curr >> 32;
            ((uint8_t *)(dst + 6 * x))[0] = d_curr >> 40;

            int64_t v_next = (((uint64_t)((const uint8_t *)(src + 6 + x * src_linesize))[0] << 40) | 
                              ((uint64_t)((const uint8_t *)(src + 6 + x * src_linesize))[1] << 32) | 
                              ((uint64_t)((const uint8_t *)(src + 6 + x * src_linesize))[2] << 24) | 
                              ((uint64_t)((const uint8_t *)(src + 6 + x * src_linesize))[3] << 16) | 
                              ((uint64_t)((const uint8_t *)(src + 6 + x * src_linesize))[4] << 8) | 
                              (uint64_t)((const uint8_t *)(src + 6 + x * src_linesize))[5]);

            uint64_t d_next = v_next;
            ((uint8_t *)(dst + dst_linesize + 6 * x))[5] = d_next;
            ((uint8_t *)(dst + dst_linesize + 6 * x))[4] = d_next >> 8;
            ((uint8_t *)(dst + dst_linesize + 6 * x))[3] = d_next >> 16;
            ((uint8_t *)(dst + dst_linesize + 6 * x))[2] = d_next >> 24;
            ((uint8_t *)(dst + dst_linesize + 6 * x))[1] = d_next >> 32;
            ((uint8_t *)(dst + dst_linesize + 6 * x))[0] = d_next >> 40;
        }
    } else {
        for (x = 0; x < w; x++) {
            int64_t v_curr = (((uint64_t)((const uint8_t *)(src + x * src_linesize))[0] << 40) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[1] << 32) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[2] << 24) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[3] << 16) | 
                              ((uint64_t)((const uint8_t *)(src + x * src_linesize))[4] << 8) | 
                              (uint64_t)((const uint8_t *)(src + x * src_linesize))[5]);

            uint64_t d_curr = v_curr;
            ((uint8_t *)(dst + 6 * x))[5] = d_curr;
            ((uint8_t *)(dst + 6 * x))[4] = d_curr >> 8;
            ((uint8_t *)(dst + 6 * x))[3] = d_curr >> 16;
            ((uint8_t *)(dst + 6 * x))[2] = d_curr >> 24;
            ((uint8_t *)(dst + 6 * x))[1] = d_curr >> 32;
            ((uint8_t *)(dst + 6 * x))[0] = d_curr >> 40;
        }
    }
}
}
