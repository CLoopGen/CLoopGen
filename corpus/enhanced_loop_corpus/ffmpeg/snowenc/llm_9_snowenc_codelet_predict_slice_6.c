#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int ref_stride;
extern uint8_t *dst8;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = (block_h * (mb_y + 1));
for (y = block_h * mb_y; y < h && y < step; y += 2) {
    int y_offset = y * w;
    int dst_offset = y * ref_stride;
    for (x = 0; x < w; x++) {
        int idx = x + y_offset;
        int dst_idx = x + dst_offset;
        int v = buf[idx] + 2064; // (128 << 4) + (1 << 3) = 2048 + 16 = 2064
        v = (v + 8) >> 4; // Combined shift with rounding
        dst8[dst_idx] = (v > 255) ? 255 : (v < 0) ? 0 : v;
    }
    if (y + 1 < h && y + 1 < step) {
        int y2_offset = (y + 1) * w;
        int dst2_offset = (y + 1) * ref_stride;
        for (x = 0; x < w; x++) {
            int idx = x + y2_offset;
            int dst_idx = x + dst2_offset;
            int v = buf[idx] + 2064;
            v = (v + 8) >> 4;
            dst8[dst_idx] = (v > 255) ? 255 : (v < 0) ? 0 : v;
        }
    }
}
}
