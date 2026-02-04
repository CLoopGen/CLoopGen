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
    int y_step = step * 2;
    for (y = sliceh_start * step; y < sliceh_end * step; y += y_step) {
        for (x = 0; x < dst_w - 3; x += 4) {
            uint8_t s0 = src[x], s1 = src[x+1], s2 = src[x+2], s3 = src[x+3];
            if (s0 != bg) {
                dst0[x] = t0;
                dst1[x] = t1;
            }
            if (s1 != bg) {
                dst0[x+1] = t0;
                dst1[x+1] = t1;
            }
            if (s2 != bg) {
                dst0[x+2] = t0;
                dst1[x+2] = t1;
            }
            if (s3 != bg) {
                dst0[x+3] = t0;
                dst1[x+3] = t1;
            }
        }
        // Handle remaining elements
        for (; x < dst_w; x++) {
            if (src[x] != bg) {
                dst0[x] = t0;
                dst1[x] = t1;
            }
        }
        src += dst_linesize * y_step;
        dst0 += dst_linesize * y_step;
        dst1 += dst_linesize * y_step;
    }
}
