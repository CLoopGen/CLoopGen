#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int width;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y++) {
    for (x = 0; x < width - 1; x += 2) {
        if (x + 1 < width - 1) {
            synthl[2 * x + 1] -= (synthl[2 * x] + synthl[2 * x + 2] + 1) >> 1;
            synthl[2 * (x + 1) + 1] -= (synthl[2 * (x + 1)] + synthl[2 * (x + 1) + 2] + 1) >> 1;
        } else {
            synthl[2 * x + 1] -= (synthl[2 * x] + synthl[2 * x + 2] + 1) >> 1;
        }
    }
    synthl[synth_width - 1] -= (3 * synthl[synth_width - 2] + 2) >> 2;
    synthl[0] += (3 * synthl[1] + 3) >> 2;
    for (x = 2; x < width - 2; x += 2) {
        synthl[2 * x] += (synthl[2 * x - 1] + synthl[2 * x + 1] + 2) >> 2;
        synthl[2 * x + 2] += (synthl[2 * x + 1] + synthl[2 * x + 3] + 2) >> 2;
    }
    if (width > 2) {
        synthl[synth_width - 2] += (2 * synthl[synth_width - 3] + 2 * synthl[synth_width - 1] + 3) >> 2;
    }
    synthl += synth_width;
}
}
