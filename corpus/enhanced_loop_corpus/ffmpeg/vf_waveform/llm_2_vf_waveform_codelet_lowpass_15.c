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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing every element sequentially, process elements with a stride of 2,
    // then handle the remaining elements in a second pass to ensure full coverage.
    int stride = 2;
    for (y = sliceh_start * step; y < sliceh_end * step; y++) {
        for (x = 0; x < dst_w; x += stride) {
            if (src[x] != bg) {
                dst0[x] = t0;
                dst1[x] = t1;
            }
        }
        // Second pass for odd indices if stride > 1
        for (x = 1; x < dst_w; x += stride) {
            if (src[x] != bg) {
                dst0[x] = t0;
                dst1[x] = t1;
            }
        }
        src += dst_linesize;
        dst0 += dst_linesize;
        dst1 += dst_linesize;
    }
}
