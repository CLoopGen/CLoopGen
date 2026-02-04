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
    for (x = 0; x < synth_width; x += 2) {
        synthl[x] += (synthl[x - synth_width] + synthl[x + synth_width] + 2) >> 2;
        if (x + 1 < synth_width)
            synthl[x + 1] += (synthl[(x + 1) - synth_width] + synthl[(x + 1) + synth_width] + 2) >> 2;
    }
}
