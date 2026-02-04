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
    for (x = 0; x < dst_w; x++) {
        dst0[x] = (src[x] != bg) ? t0 : dst0[x];
        dst1[x] = (src[x] != bg) ? t1 : dst1[x];
    }
    src += dst_linesize;
    dst0 += dst_linesize;
    dst1 += dst_linesize;
}
}
