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
for (y = sliceh_start * step; y < sliceh_end * step; y++) {
    int skip_update = 1;
    for (x = 0; x < dst_w; x++) {
        if (src[x] != bg) {
            skip_update = 0;
            break;
        }
    }
    if (!skip_update) {
        for (x = 0; x < dst_w; x++) {
            if (src[x] != bg) {
                dst0[x] = t0;
                dst1[x] = t1;
            }
        }
    }
    src += dst_linesize;
    dst0 += dst_linesize;
    dst1 += dst_linesize;
}
}
