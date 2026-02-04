#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int x;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dwtcoef *restrict local_synthl = synthl;
    ptrdiff_t width = synth_width;
    for (x = 0; x < width; x++) {
        dwtcoef temp = (2 * local_synthl[width + x] + 2) >> 2;
        local_synthl[x] += temp;
    }
}
