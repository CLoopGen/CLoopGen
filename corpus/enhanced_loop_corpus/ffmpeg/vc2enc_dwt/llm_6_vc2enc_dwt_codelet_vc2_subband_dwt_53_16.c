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
    dwtcoef *l_synthl = synthl;
    ptrdiff_t w = synth_width;
    for (x = 0; x < w; x++) {
        dwtcoef temp = (l_synthl[x - w] + l_synthl[x + w] + 2) >> 2;
        l_synthl[x] += temp;
    }
}
