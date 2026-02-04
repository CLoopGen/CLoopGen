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
    uint8_t buffer[6];
    for (x = 0; x < w; x++) {
        int64_t v = (((uint64_t)((const uint8_t *)(src + x * src_linesize))[0] << 40) | ((uint64_t)((const uint8_t *)(src + x * src_linesize))[1] << 32) | ((uint64_t)((const uint8_t *)(src + x * src_linesize))[2] << 24) | ((uint64_t)((const uint8_t *)(src + x * src_linesize))[3] << 16) | ((uint64_t)((const uint8_t *)(src + x * src_linesize))[4] << 8) | (uint64_t)((const uint8_t *)(src + x * src_linesize))[5]);
        uint64_t d = v;
        buffer[5] = (d);
        buffer[4] = (d) >> 8;
        buffer[3] = (d) >> 16;
        buffer[2] = (d) >> 24;
        buffer[1] = (d) >> 32;
        buffer[0] = (d) >> 40;
        for (int i = 0; i < 6; i++) {
            ((uint8_t *)(dst + 6 * x))[i] = buffer[i];
        }
    }
}
}
