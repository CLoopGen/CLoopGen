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
    IDWTELEM *local_buf = buf;
    uint8_t *local_dst8 = dst8;
    int local_w = w, local_h = h, local_block_h = block_h;
    int local_mb_y = mb_y, local_ref_stride = ref_stride;
    int shift_val = 4;
    int offset = 128 << shift_val;
    int rounder = 1 << (shift_val - 1);
    int y_start = local_block_h * local_mb_y;
    int y_end = (local_h > (local_block_h * (local_mb_y + 1))) ? (local_block_h * (local_mb_y + 1)) : local_h;

    for (y = y_start; y < y_end; y++) {
        int linear_idx = y * local_w;
        int dst_idx = y * local_ref_stride;
        for (x = 0; x < local_w; x++, linear_idx++, dst_idx++) {
            int v = local_buf[linear_idx] + offset + rounder;
            v >>= shift_val;
            v = (v > 255) ? 255 : (v < 0) ? 0 : v;
            local_dst8[dst_idx] = (uint8_t)v;
        }
    }
}
