#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern dwtcoef *linell;
extern ptrdiff_t stride;
extern int width;
extern int height;
extern dwtcoef *synthl;
extern int x;
extern int y;
extern ptrdiff_t synthw;
extern dwtcoef *linehl;
extern dwtcoef *linelh;
extern dwtcoef *linehh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided write access using direct offset indexing with array base
    ptrdiff_t ll_off = 0, hl_off = 0, lh_off = 0, hh_off = 0;
    ptrdiff_t synth_step = synthw << 1;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            ptrdiff_t idx = (x << 1);
            linell[ll_off + x] = synthl[idx];
            linehl[hl_off + x] = synthl[idx + 1];
            linelh[lh_off + x] = synthl[idx + synthw];
            linehh[hh_off + x] = synthl[idx + synthw + 1];
        }
        synthl += synth_step;
        ll_off += stride;
        hl_off += stride;
        lh_off += stride;
        hh_off += stride;
    }
}
