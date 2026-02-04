#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern int x;
extern int y;
extern dwtcoef *datal;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y++) {
    if (y % 2 == 0) {
        for (x = 0; x < synth_width; x++) {
            synthl[x] = datal[x] * 2;
        }
    } else {
        for (x = 0; x < synth_width; x++) {
            synthl[x] = datal[x] + 1;
        }
    }
    synthl += synth_width;
    datal += stride;
}
}
