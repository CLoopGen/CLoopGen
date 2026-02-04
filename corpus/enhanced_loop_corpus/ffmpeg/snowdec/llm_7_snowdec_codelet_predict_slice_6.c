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
    const int shift = 4;
    const int add_offset = (128 << shift) + (1 << (shift - 1));
    int y_start = local_block_h * local_mb_y;
    int y_end = (local_h > local_block_h * (local_mb_y + 1)) ? local_block_h * (local_mb_y + 1) : local_h;

    for (y = y_start; y < y_end; y++) {
        int src_offset = y * local_w;
        int dst_offset = y * local_ref_stride;
        int temp_vals[64]; // Local accumulation to introduce WAW and RAW dependencies within the loop body

        for (x = 0; x < local_w && x < 64; x++) {
            int raw_val = local_buf[src_offset + x];
            temp_vals[x] = raw_val + add_offset; // RAW: temp_vals[x] depends on raw_val
        }

        for (x = 0; x < local_w && x < 64; x++) {
            int v = temp_vals[x] >> shift; // WAW: staged write via temp array
            if (v & (~255))
                v = ~(v >> 31);
            local_dst8[dst_offset + x] = (uint8_t)v;
        }

        // Introduce artificial loop-carried dependency via reuse of 'x' state (though logically same)
        // This simulates a reduced optimization opportunity due to carried state
        if (x > 0) {
            x--; // WAR hazard introduced but controlled; no actual data loss
            x++;
        }
    }
}
