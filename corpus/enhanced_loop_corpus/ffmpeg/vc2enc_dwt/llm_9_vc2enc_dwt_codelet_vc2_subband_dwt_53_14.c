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
    for (x = 0; x < synth_width / 2; x++) {
        dwtcoef temp1 = synthl[synth_width + x];
        dwtcoef temp2 = synthl[synth_width + synth_width - 1 - x];
        synthl[x] += (temp1 + temp2 + 1) >> 2;
    }
}
