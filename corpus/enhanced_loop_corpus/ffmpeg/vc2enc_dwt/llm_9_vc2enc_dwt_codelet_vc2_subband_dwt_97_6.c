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
    dwtcoef val1 = synthl[x + synth_width];
    dwtcoef val2 = synthl[x + synth_width + synth_width/2];
    synthl[x] += (val1 + val2 + val1 + val2 + 4) >> 3;
}
}
