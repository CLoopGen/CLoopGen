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
        int base_idx = y * local_w;
        int dst_base_idx = y * local_ref_stride;
        for (x = 0; x < local_w; x++) {
            int data = local_buf[base_idx + x];
            int v = data + offset + rounder;
            v >>= shift_val;
            if (v & (~255))
                v = ~(v >> 31);
            local_dst8[dst_base_idx + x] = (uint8_t)v;
        }
    }
}
