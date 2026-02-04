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
for (y = 0; y < dst_h; y++) {
    for (x = slicew_start * step; x < slicew_end * step; x += 2) {
        if (src[x] != bg && src[x+1] != bg) {
            dst0[x] = t0;
            dst1[x] = t1;
            dst0[x+1] = t0;
            dst1[x+1] = t1;
        } else {
            if (src[x] != bg) {
                dst0[x] = t0;
                dst1[x] = t1;
            }
            if (x+1 < slicew_end * step && src[x+1] != bg) {
                dst0[x+1] = t0;
                dst1[x+1] = t1;
            }
        }
    }
    src += dst_linesize;
    dst0 += dst_linesize;
    dst1 += dst_linesize;
}
}
