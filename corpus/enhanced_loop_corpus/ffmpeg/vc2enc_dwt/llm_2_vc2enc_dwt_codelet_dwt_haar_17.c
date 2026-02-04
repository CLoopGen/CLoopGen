#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern  int s;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern dwtcoef *datal;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via pointer arithmetic with unrolling
    dwtcoef *dl = datal;
    dwtcoef *sl = synthl;
    ptrdiff_t dw = synth_width;
    ptrdiff_t ds = stride;
    int shift = s;

    for (y = 0; y < synth_height; y++) {
        dwtcoef *dly = dl + y * ds;
        dwtcoef *sly = sl + y * dw;
        for (x = 0; x < synth_width; x += 2) {
            dwtcoef val0 = dly[x + 0];
            dwtcoef val1 = dly[x + 1];
            dwtcoef temp = (val1 << shift) - (val0 << shift);
            sly[x + 1] = temp;
            sly[x + 0] = (val0 << shift) + ((temp + 1) >> 1);
        }
    }
}
