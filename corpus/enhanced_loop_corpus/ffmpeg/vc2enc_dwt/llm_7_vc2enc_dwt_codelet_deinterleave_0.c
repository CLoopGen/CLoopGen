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
    for (y = 0; y < height; y++) {
        dwtcoef *base_synth = synthl + (y << 1) * synthw;
        dwtcoef *ll_row = linell;
        dwtcoef *lh_row = linelh;
        dwtcoef *hl_row = linehl;
        dwtcoef *hh_row = linehh;

        for (x = 0; x < width; x++) {
            ptrdiff_t offset = (x << 1);
            linell[x] = base_synth[offset];
            linehl[x] = base_synth[offset + 1];
            linelh[x] = base_synth[offset + synthw];
            linehh[x] = base_synth[offset + synthw + 1];
        }

        linell += stride;
        linelh += stride;
        linehl += stride;
        linehh += stride;
    }
}
