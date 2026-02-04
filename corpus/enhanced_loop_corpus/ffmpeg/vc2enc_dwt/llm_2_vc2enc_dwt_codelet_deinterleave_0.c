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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    dwtcoef *s = synthl;
    dwtcoef *ll = linell;
    dwtcoef *hl = linehl;
    dwtcoef *lh = linelh;
    dwtcoef *hh = linehh;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int base = x << 1;
            ll[x] = s[base];
            hl[x] = s[base + 1];
            lh[x] = s[base + synthw];
            hh[x] = s[base + synthw + 1];
        }
        s += synthw << 1;
        ll += stride;
        hl += stride;
        lh += stride;
        hh += stride;
    }
}
