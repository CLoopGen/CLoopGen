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
    uint16_t temp;
    for (y = 0; y < h; y++, src += sstride, frame_ant += w) {
        temp = 0;
        for (x = 0; x < w; x++) {
            uint16_t val = (depth == 8 ? src[x] : (((const av_alias16 *)(src + x * 2))->u16));
            temp = (val << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1); // Introduce dependency: each iteration uses previous 'temp'
            frame_ant[x] = temp;
        }
    }
}
