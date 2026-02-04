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
    dst[y * dst_linesize] = slice[y * slice_linesize] * weights[y * dst_linesize];
    for (x = 1; x < w; x++) {
        dst[y * dst_linesize + x] = slice[y * slice_linesize + x] * weights[y * dst_linesize + x];
    }
}
}
