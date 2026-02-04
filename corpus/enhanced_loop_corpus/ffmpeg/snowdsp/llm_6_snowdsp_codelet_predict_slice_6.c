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
    int local_w = w;
    int local_h = h;
    int local_block_h = block_h;
    int local_mb_y = mb_y;
    int local_ref_stride = ref_stride;

    for (y = local_block_h * local_mb_y; y < ((local_h) > (local_block_h * (local_mb_y + 1)) ? (local_block_h * (local_mb_y + 1)) : (local_h)); y++) {
        int offset = y * local_w;
        int dst_offset = y * local_ref_stride;
        for (x = 0; x < local_w; x++) {
            int idx = offset + x;
            int v = local_buf[idx] + (128 << 4);
            v += (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            local_dst8[dst_offset + x] = (uint8_t)v;
        }
    }
}
