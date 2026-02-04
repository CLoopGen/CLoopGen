#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int dst_linesize;
extern  int sliceh_start;
extern  int sliceh_end;
extern  int step;
extern int y;
extern  int bg;
extern  int dst_w;
extern  int t0;
extern  int t1;
extern uint8_t *dst0;
extern uint8_t *dst1;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_t0 = t0;
    for (y = sliceh_start * step; y < sliceh_end * step; y++) {
        for (x = 0; x < dst_w; x += 2) {
            if (x + 1 < dst_w && src[x] != bg && src[x + 1] != bg) {
                dst0[x] = prev_t0;
                dst1[x] = t1;
                dst0[x + 1] = prev_t0 + 1;
                dst1[x + 1] = t1 - 1;
                prev_t0 += 2;
            } else if (src[x] != bg) {
                dst0[x] = prev_t0;
                dst1[x] = t1;
                prev_t0++;
            }
        }
        src += dst_linesize;
        dst0 += dst_linesize;
        dst1 += dst_linesize;
    }
}
