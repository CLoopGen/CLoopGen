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
    uint16_t shift_val = 16 - depth;
    uint16_t round_val = ((1 << shift_val) - 1) >> 1;
    for (y = 0; y < h; y++, src += sstride, frame_ant += w) {
        if (depth == 8) {
            for (x = 0; x < w; x++) {
                frame_ant[x] = (src[x] << shift_val) + round_val;
            }
        } else {
            for (x = 0; x < w; x++) {
                frame_ant[x] = (((const av_alias16 *)(src + x * 2))->u16 << shift_val) + round_val;
            }
        }
    }
}
