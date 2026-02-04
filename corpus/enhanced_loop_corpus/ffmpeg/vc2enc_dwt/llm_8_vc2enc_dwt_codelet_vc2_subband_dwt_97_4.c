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
    for (y = 2; y < height - 3; y += 2) {
        for (x = 1; x < synth_width - 1; x++) {
            dwtcoef temp1 = synthl[x - 2 * synth_width];
            dwtcoef temp2 = synthl[x];
            dwtcoef temp3 = synthl[x + 2 * synth_width];
            dwtcoef temp4 = synthl[x + 4 * synth_width];
            dwtcoef sum = (9 * temp2 + 9 * temp3 - temp1 - temp4 + 8) >> 4;
            synthl[x + synth_width] -= sum;
        }
        synthl += synth_width << 2; // Advance two rows at a time due to y += 2
    }
}
