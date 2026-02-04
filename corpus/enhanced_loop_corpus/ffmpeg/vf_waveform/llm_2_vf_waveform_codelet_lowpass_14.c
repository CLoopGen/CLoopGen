#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int dst_linesize;
extern  int slicew_start;
extern  int slicew_end;
extern  int step;
extern int y;
extern  int bg;
extern  int dst_h;
extern  int t0;
extern  int t1;
extern uint8_t *dst0;
extern uint8_t *dst1;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint8_t *src_ptr = src;
    uint8_t *dst0_ptr = dst0;
    uint8_t *dst1_ptr = dst1;

    for (y = 0; y < dst_h; y++) {
        uint8_t *local_src = src_ptr;
        uint8_t *local_dst0 = dst0_ptr;
        uint8_t *local_dst1 = dst1_ptr;

        for (int offset = slicew_start * step; offset < slicew_end * step; offset++) {
            if (*(local_src + offset) != bg) {
                *(local_dst0 + offset) = t0;
                *(local_dst1 + offset) = t1;
            }
        }

        src_ptr += dst_linesize;
        dst0_ptr += dst_linesize;
        dst1_ptr += dst_linesize;
    }
}
