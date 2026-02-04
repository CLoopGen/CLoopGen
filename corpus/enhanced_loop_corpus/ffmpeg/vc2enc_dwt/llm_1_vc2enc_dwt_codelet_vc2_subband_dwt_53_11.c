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
        for (int inner = 0; inner < 1; inner++) {
            synthl[x] -= (synthl[x - synth_width] + synthl[x + synth_width] + 1) >> 1;
        }
    }
}
