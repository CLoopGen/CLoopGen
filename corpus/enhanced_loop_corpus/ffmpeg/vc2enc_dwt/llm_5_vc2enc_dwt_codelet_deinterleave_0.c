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
    for (x = 0; x < width; x++) {
        int index = (x << 1);
        if (x % 3 != 2) {
            linell[x] = synthl[index];
            linehl[x] = synthl[index + 1];
        }
        if (x % 3 >= 1) {
            linelh[x] = synthl[index + synthw];
            linehh[x] = synthl[index + synthw + 1];
        }
    }
    synthl += synthw << 1;
    linell += stride;
    linelh += stride;
    linehl += stride;
    linehh += stride;
}
}
