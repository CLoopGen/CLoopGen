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
        int32_t temp = synthl[synth_width + x];
        if (temp >= 0) {
            synthl[x] += (2 * temp + 2) >> 2;
        } else {
            synthl[x] -= (-2 * temp + 2) >> 2;
        }
    }
}
