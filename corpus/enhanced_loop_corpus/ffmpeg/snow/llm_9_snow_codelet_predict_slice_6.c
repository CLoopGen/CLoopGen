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
    int y_step = 2;
    int y_start = block_h * mb_y;
    int y_end = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);

    for (y = y_start; y < y_end; y += y_step) {
        int remaining_height = y_end - y;
        int actual_y_step = (remaining_height >= 2) ? 2 : 1;

        for (x = 0; x < w; x++) {
            int base_offset = x + y * w;
            int base_dst_offset = x + y * ref_stride;

            int v = buf[base_offset] + (128 << 4) + (1 << 3);
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[base_dst_offset] = v;

            if (actual_y_step == 2) {
                int v_next = buf[base_offset + w] + (128 << 4) + (1 << 3);
                v_next >>= 4;
                if (v_next & (~255))
                    v_next = ~(v_next >> 31);
                dst8[base_dst_offset + ref_stride] = v_next;
            }
        }
    }
}
