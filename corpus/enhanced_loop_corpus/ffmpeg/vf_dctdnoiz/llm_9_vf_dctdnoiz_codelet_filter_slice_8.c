#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern  int w;
extern  int slice_start;
extern  int slice_end;
extern  int dst_linesize;
extern  int slice_linesize;
extern float *dst;
extern  float *weights;
extern float *slice;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = slice_start; y < slice_end; y += 2) {
    for (x = 0; x < w; x++) {
        dst[x] = slice[x] * weights[x];
        if (y + 1 < slice_end) {
            dst[dst_linesize + x] = slice[slice_linesize + x] * weights[dst_linesize + x];
        }
    }
    slice += 2 * slice_linesize;
    dst += 2 * dst_linesize;
    weights += 2 * dst_linesize;
}
}
