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
    dwtcoef *synth_ptr = synthl;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            dwtcoef val_ll = synth_ptr[(x << 1)];
            dwtcoef val_hl = synth_ptr[(x << 1) + 1];
            dwtcoef val_lh = synth_ptr[(x << 1) + synthw];
            dwtcoef val_hh = synth_ptr[(x << 1) + synthw + 1];

            linell[x] = val_ll;
            linehl[x] = val_hl;
            linelh[x] = val_lh;
            linehh[x] = val_hh;
        }
        synth_ptr += synthw << 1;
        linell += stride;
        linelh += stride;
        linehl += stride;
        linehh += stride;
    }
}
