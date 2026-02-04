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
    // Variant 1: Strided memory access with step size of 2
    // Processes only even indices to create a strided access pattern
    for (x = 0; x < synth_width; x += 2) {
        if (x - synth_width >= 0 || x + synth_width < 2 * synth_width) {
            synthl[x] += (synthl[x - synth_width] + synthl[x + synth_width] + 2) >> 2;
        }
    }
    // Handle remaining odd index if synth_width is odd
    for (x = 1; x < synth_width; x += 2) {
        if (x - synth_width >= 0 || x + synth_width < 2 * synth_width) {
            synthl[x] += (synthl[x - synth_width] + synthl[x + synth_width] + 2) >> 2;
        }
    }
}
