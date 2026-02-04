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
for (y = 0; y < dst_h; y += 2) {
    uint8_t *src0 = src;
    uint8_t *dst0_0 = dst0;
    uint8_t *dst1_0 = dst1;
    uint8_t *src1 = src + dst_linesize;
    uint8_t *dst0_1 = dst0 + dst_linesize;
    uint8_t *dst1_1 = dst1 + dst_linesize;

    for (x = slicew_start * step; x < slicew_end * step; x++) {
        if (src0[x] != bg) {
            dst0_0[x] = t0;
            dst1_0[x] = t1;
        }
        if (y + 1 < dst_h && src1[x] != bg) {
            dst0_1[x] = t0;
            dst1_1[x] = t1;
        }
    }

    src += 2 * dst_linesize;
    dst0 += 2 * dst_linesize;
    dst1 += 2 * dst_linesize;
}
}
