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
    for (x = 1; x < synth_width - 1; x++) {
        dwtcoef left  = synthl[x - synth_width - 1];
        dwtcoef right = synthl[x + synth_width + 1];
        dwtcoef center = synthl[x];
        dwtcoef avg = (left + 2 * center + right + 4) >> 3;
        synthl[x] += avg;
    }
}
