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
        for (x = 1; x < synth_width; x++)
            synthl[x] = synthl[x-1] + (datal[x] - datal[x-1]) * 2;
        if (synth_width > 0)
            synthl[0] = datal[0] * 2;
        synthl += synth_width;
        datal += stride;
    }
}
