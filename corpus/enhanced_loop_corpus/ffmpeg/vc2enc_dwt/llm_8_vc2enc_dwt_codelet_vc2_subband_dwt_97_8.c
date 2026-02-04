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
    for (x = synth_width / 4; x < 3 * synth_width / 4; x++) {
        dwtcoef temp1 = synthl[x - synth_width];
        dwtcoef temp2 = synthl[x + synth_width];
        dwtcoef sum = temp1 + temp2 + 3;
        synthl[x] += sum >> 2;
    }
}
