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
for (y = 0; y < h; y++ , dst += dst_linesize , src += src_linesize) {
    for (x = 0; x < w; x++) {
        const uint8_t *s = &((const uint8_t *)(src + 6))[x];
        uint8_t *d = &((uint8_t *)(dst + 6*x))[0];
        int64_t v = (((uint64_t)s[0 * w] << 40) |
                     ((uint64_t)s[1 * w] << 32) |
                     ((uint64_t)s[2 * w] << 24) |
                     ((uint64_t)s[3 * w] << 16) |
                     ((uint64_t)s[4 * w] << 8)  |
                     (uint64_t)s[5 * w]);
        uint64_t val = v;
        d[5] = val;
        d[4] = val >> 8;
        d[3] = val >> 16;
        d[2] = val >> 24;
        d[1] = val >> 32;
        d[0] = val >> 40;
    }
}
}
