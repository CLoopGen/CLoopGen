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
    ptrdiff_t l_synth_width = synth_width;
    dwtcoef temp;

    for (x = 0; x < l_synth_width; x++) {
        temp = (l_synthl[x + l_synth_width] + l_synthl[x + l_synth_width] + 2) >> 2;
        l_synthl[x] += temp;
    }
}
