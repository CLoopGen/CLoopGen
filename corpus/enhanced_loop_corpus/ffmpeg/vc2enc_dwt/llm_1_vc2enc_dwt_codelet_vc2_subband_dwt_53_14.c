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
    if (synth_width > 0) {
        x = 0;
        for (int i = 0; i < synth_width; i++) {
            synthl[x] += (2 * synthl[synth_width + x] + 2) >> 2;
            x++;
        }
    }
}
