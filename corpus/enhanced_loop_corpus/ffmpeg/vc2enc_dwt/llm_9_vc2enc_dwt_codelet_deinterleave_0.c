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
for (y = 0; y < height; y += 2) {
    if (y + 1 < height) {
        for (x = 0; x < width; x++) {
            linell[x] = synthl[(x << 1)];
            linehl[x] = synthl[(x << 1) + 1];
            linelh[x] = synthl[(x << 1) + synthw];
            linehh[x] = synthl[(x << 1) + synthw + 1];

            dwtcoef *next_synthl = synthl + (synthw << 1);
            dwtcoef *next_linell = linell + stride;
            dwtcoef *next_linelh = linelh + stride;
            dwtcoef *next_linehl = linehl + stride;
            dwtcoef *next_linehh = linehh + stride;

            next_linell[x] = next_synthl[(x << 1)];
            next_linehl[x] = next_synthl[(x << 1) + 1];
            next_linelh[x] = next_synthl[(x << 1) + synthw];
            next_linehh[x] = next_synthl[(x << 1) + synthw + 1];
        }
        synthl += (synthw << 1) * 2;
        linell += stride * 2;
        linelh += stride * 2;
        linehl += stride * 2;
        linehh += stride * 2;
    } else {
        for (x = 0; x < width; x++) {
            linell[x] = synthl[(x << 1)];
            linehl[x] = synthl[(x << 1) + 1];
            linelh[x] = synthl[(x << 1) + synthw];
            linehh[x] = synthl[(x << 1) + synthw + 1];
        }
        synthl += synthw << 1;
        linell += stride;
        linelh += stride;
        linehl += stride;
        linehh += stride;
    }
}
}
