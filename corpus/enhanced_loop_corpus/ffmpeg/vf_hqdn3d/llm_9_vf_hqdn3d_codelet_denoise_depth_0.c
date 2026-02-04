#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *src;
extern int w;
extern int h;
extern int sstride;
extern int depth;
extern long x;
extern long y;
extern uint16_t *frame_ant;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (y = 0; y < h; y += 1, src += sstride, frame_ant += w * 2)
    for (x = 0; x < w; x += step) {
        int x1 = x;
        int x2 = x + 1;
        if (x2 < w) {
            uint16_t val1 = (depth == 8 ? src[x1] : (((const av_alias16 *)(src + x1 * 2))->u16));
            uint16_t val2 = (depth == 8 ? src[x2] : (((const av_alias16 *)(src + x2 * 2))->u16));
            frame_ant[x1] = (val1 << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1);
            frame_ant[x2] = (val2 << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1);
        } else {
            frame_ant[x1] = (depth == 8 ? src[x1] : (((const av_alias16 *)(src + x1 * 2))->u16)) << (16 - depth);
            frame_ant[x1] += ((1 << (16 - depth)) - 1) >> 1;
        }
    }
}
