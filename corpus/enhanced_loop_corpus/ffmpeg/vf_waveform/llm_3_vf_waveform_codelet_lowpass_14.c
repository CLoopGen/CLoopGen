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
    // Variant 2: Strided Memory Access (processing every 2nd element in a strided pattern)
    for (y = 0; y < dst_h; y++) {
        for (x = slicew_start * step; x < slicew_end * step; x += 2) {  // Stride of 2
            // Handle two elements per iteration to maintain coverage
            int x1 = x;
            int x2 = x + 1;

            if (x1 < slicew_end * step) {
                if (src[x1] != bg) {
                    dst0[x1] = t0;
                    dst1[x1] = t1;
                }
            }

            if (x2 < slicew_end * step) {
                if (src[x2] != bg) {
                    dst0[x2] = t0;
                    dst1[x2] = t1;
                }
            }
        }
        src += dst_linesize;
        dst0 += dst_linesize;
        dst1 += dst_linesize;
    }
}
