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
    for (int offset = slicew_start * step; offset < slicew_end * step; offset++) {
        if (*(src + offset) != bg) {
            *(dst0 + offset) = t0;
            *(dst1 + offset) = t1;
        }
    }
    src += dst_linesize;
    dst0 += dst_linesize;
    dst1 += dst_linesize;
}
}
