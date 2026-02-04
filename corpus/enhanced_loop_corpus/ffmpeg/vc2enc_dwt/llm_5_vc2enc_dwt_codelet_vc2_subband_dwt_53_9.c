#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern dwtcoef *datal;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y++) {
    int skip_row = (y % 3 == 0);
    for (x = 0; x < synth_width; x++) {
        if (!skip_row) {
            synthl[x] = datal[x] << 1;
        }
    }
    if (!skip_row) {
        synthl += synth_width;
    }
    datal += stride;
}
}
