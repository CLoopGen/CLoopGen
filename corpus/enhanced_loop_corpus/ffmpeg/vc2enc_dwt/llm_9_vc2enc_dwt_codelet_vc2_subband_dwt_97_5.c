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
    dwtcoef temp1 = synthl[x - synth_width];
    dwtcoef temp2 = synthl[x - 3 * synth_width];
    dwtcoef temp3 = synthl[x - 1 * synth_width];
    dwtcoef temp4 = synthl[x - 5 * synth_width];
    dwtcoef val1 = (17 * temp1 - temp2 + 8) >> 4;
    dwtcoef val2 = (9 * temp2 + 8 * temp3 - temp4 + 8) >> 4;
    synthl[x] -= val1;
    synthl[x - 2 * synth_width] -= val2;
}
}
