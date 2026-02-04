#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int height;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < height - 1; y++) {
    x = 0;
    for (; x < synth_width; x++) {
        synthl[x + synth_width] -= (synthl[x] + synthl[x + synth_width * 2] + 1) >> 1;
    }
    synthl += (synth_width << 1);
}
}
