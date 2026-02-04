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
    // Variant 2: Reverse Consecutive Access Pattern
    ptrdiff_t x;
    // Traverse the array from the end to the beginning
    for (x = synth_width - 1; x >= 0; x--) {
        synthl[x] += (2 * synthl[synth_width + x] + 2) >> 2;
    }
}
