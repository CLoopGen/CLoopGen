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
for (y = slice_start; y < slice_end; y++) {
    for (x = 0; x < w; x += 2) {
        dst[x] = slice[x] * weights[x];
        if (x + 1 < w) {
            dst[x + 1] = slice[x + 1] * weights[x + 1];
        }
    }
    slice += slice_linesize;
    dst += dst_linesize;
    weights += dst_linesize;
}
}
