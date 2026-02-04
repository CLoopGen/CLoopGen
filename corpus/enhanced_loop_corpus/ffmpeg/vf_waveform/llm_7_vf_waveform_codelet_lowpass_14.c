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
    uint8_t local_bg = bg;
    uint8_t local_t0 = t0;
    uint8_t local_t1 = t1;
    uint8_t *local_src, *local_dst0, *local_dst1;
    for (y = 0; y < dst_h; y++) {
        local_src = src + y * dst_linesize;
        local_dst0 = dst0 + y * dst_linesize;
        local_dst1 = dst1 + y * dst_linesize;
        for (x = slicew_start * step; x < slicew_end * step; x++) {
            uint8_t val = local_src[x];
            if (val != local_bg) {
                local_dst0[x] = local_t0;
                local_dst1[x] = local_t1;
            }
        }
    }
}
