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
for (y = 2; y < height - 2; y++) {
    for (x = 1; x < synth_width - 1; x++) {
        dwtcoef temp1 = synthl[x] + synthl[x + synth_width * 2];
        dwtcoef temp2 = synthl[x - 1] + synthl[x + 1];
        dwtcoef avg = (temp1 + temp2 + 2) >> 2;
        synthl[x + synth_width] -= avg;
    }
    synthl += (synth_width << 1);
}
}
