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
int shift_val = 4;
int add_const = (128 << shift_val) + (1 << (shift_val - 1));
int limit_y = ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h));

for (y = block_h * mb_y; y < limit_y; y += 2) {
    int base_idx = y * w;
    int base_dst = y * ref_stride;
    for (x = 0; x < w; x++) {
        int idx = base_idx + x;
        int dst_idx = base_dst + x;
        int v = buf[idx] + add_const;
        v >>= shift_val;
        v = (v > 255) ? 255 : (v < 0) ? 0 : v;
        dst8[dst_idx] = v;

        if (y + 1 < limit_y) {
            int idx2 = base_idx + w + x;
            int dst_idx2 = base_dst + ref_stride + x;
            int v2 = buf[idx2] + add_const;
            v2 >>= shift_val;
            v2 = (v2 > 255) ? 255 : (v2 < 0) ? 0 : v2;
            dst8[dst_idx2] = v2;
        }
    }
}
}
