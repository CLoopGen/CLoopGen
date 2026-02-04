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
    if (synth_width <= 0) return;
    for (x = 0; x < synth_width; x++) {
        ptrdiff_t idx_minus = x - synth_width;
        ptrdiff_t idx_plus = x + synth_width;
        dwtcoef val_minus = synthl[idx_minus];
        dwtcoef val_plus = synthl[idx_plus];
        dwtcoef avg = (val_minus + val_plus + 1) >> 1;
        synthl[x] -= avg;
    }
}
