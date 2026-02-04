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
    for (x = 0; x < synth_width; x++) {
        ptrdiff_t idx_low = x - synth_width;
        ptrdiff_t idx_high = x + synth_width;
        if (idx_low >= 0 && idx_high >= 0) {
            dwtcoef sum = synthl[idx_low] + synthl[idx_high] + 2;
            synthl[x] += (sum >> 2);
        }
    }
}
