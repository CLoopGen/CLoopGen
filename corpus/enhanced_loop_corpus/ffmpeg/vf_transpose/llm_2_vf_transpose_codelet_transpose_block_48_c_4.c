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
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (x = 0; x < w; x++) {
        int64_t v = (((uint64_t)((const uint8_t *)(src_row))[0] << 40) |
                    ((uint64_t)((const uint8_t *)(src_row))[1] << 32) |
                    ((uint64_t)((const uint8_t *)(src_row))[2] << 24) |
                    ((uint64_t)((const uint8_t *)(src_row))[3] << 16) |
                    ((uint64_t)((const uint8_t *)(src_row))[4] << 8)  |
                    (uint64_t)((const uint8_t *)(src_row))[5]);
        uint64_t d = v;
        ((uint8_t *)(dst_row))[5] = d;
        ((uint8_t *)(dst_row))[4] = d >> 8;
        ((uint8_t *)(dst_row))[3] = d >> 16;
        ((uint8_t *)(dst_row))[2] = d >> 24;
        ((uint8_t *)(dst_row))[1] = d >> 32;
        ((uint8_t *)(dst_row))[0] = d >> 40;
        src_row += src_linesize;
        dst_row += 6;
    }
}
}
