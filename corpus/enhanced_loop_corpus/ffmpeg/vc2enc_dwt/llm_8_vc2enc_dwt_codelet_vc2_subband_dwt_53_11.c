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
    for (x = synth_width / 4; x < synth_width - synth_width / 4; x += 2) {
        dwtcoef temp1 = synthl[x - synth_width];
        dwtcoef temp2 = synthl[x + synth_width];
        dwtcoef avg = (temp1 + temp2 + 1) >> 1;
        synthl[x] -= avg;
        if (x + 1 < synth_width - synth_width / 4) {
            dwtcoef temp1_next = synthl[(x + 1) - synth_width];
            dwtcoef temp2_next = synthl[(x + 1) + synth_width];
            dwtcoef avg_next = (temp1_next + temp2_next + 1) >> 1;
            synthl[x + 1] -= avg_next;
        }
    }
}
