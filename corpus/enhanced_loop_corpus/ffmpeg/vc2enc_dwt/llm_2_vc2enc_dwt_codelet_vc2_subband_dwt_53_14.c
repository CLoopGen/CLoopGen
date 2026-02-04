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
    // Variant 1: Strided Memory Access (access every 2nd element in chunks)
    ptrdiff_t i;
    // Process even indices first with stride of 2
    for (i = 0; i < synth_width; i += 2) {
        if (i < synth_width) {
            synthl[i] += (2 * synthl[synth_width + i] + 2) >> 2;
        }
        if (i + 1 < synth_width) {
            synthl[i + 1] += (2 * synthl[synth_width + (i + 1)] + 2) >> 2;
        }
    }
}
