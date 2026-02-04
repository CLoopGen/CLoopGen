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
    // Variant 2: Consecutive Block Memory Access Pattern
    // Restructure memory access to improve cache locality by unrolling the loop
    // and processing multiple elements per iteration consecutively.
    // Also aligns writes to likely cacheline boundaries (e.g., 16-byte alignment).
    int x_unrolled;
    int remainder = dst_w % 4;
    
    for (y = sliceh_start * step; y < sliceh_end * step; y++) {
        // Process 4 elements at a time for better throughput
        for (x_unrolled = 0; x_unrolled < dst_w - remainder; x_unrolled += 4) {
            if (src[x_unrolled]     != bg) { dst0[x_unrolled] = t0; dst1[x_unrolled] = t1; }
            if (src[x_unrolled + 1] != bg) { dst0[x_unrolled + 1] = t0; dst1[x_unrolled + 1] = t1; }
            if (src[x_unrolled + 2] != bg) { dst0[x_unrolled + 2] = t0; dst1[x_unrolled + 2] = t1; }
            if (src[x_unrolled + 3] != bg) { dst0[x_unrolled + 3] = t0; dst1[x_unrolled + 3] = t1; }
        }
        // Handle leftover elements
        for (x = dst_w - remainder; x < dst_w; x++) {
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
