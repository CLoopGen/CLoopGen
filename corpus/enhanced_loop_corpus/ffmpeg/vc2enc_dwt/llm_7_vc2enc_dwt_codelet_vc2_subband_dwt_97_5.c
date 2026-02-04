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
for (x = 2; x < synth_width; x++) {
    dwtcoef val1 = synthl[x - synth_width];
    dwtcoef val2 = synthl[x - 3 * synth_width];
    dwtcoef val3 = synthl[x - 1 * synth_width];
    dwtcoef val4 = synthl[x - 5 * synth_width];
    dwtcoef update1 = (17 * val1 - val2 + 8) >> 4;
    dwtcoef update2 = (9 * val2 + 8 * val3 - val4 + 8) >> 4;
    synthl[x] -= update1;
    synthl[x - 2 * synth_width] -= update2;
}
}
