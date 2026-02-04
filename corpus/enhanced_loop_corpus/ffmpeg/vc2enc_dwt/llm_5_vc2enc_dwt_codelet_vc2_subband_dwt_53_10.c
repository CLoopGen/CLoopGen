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
    x = 0;
    if (width >= 2) {
        for (; x < width - 1; x++) {
            int idx = 2 * x;
            synthl[idx + 1] -= (synthl[idx] + synthl[idx + 2] + 1) >> 1;
        }
        synthl[synth_width - 1] -= (2 * synthl[synth_width - 2] + 1) >> 1;
        synthl[0] += (2 * synthl[1] + 2) >> 2;
        x = 1;
        for (; x < width - 1; x++) {
            int idx = 2 * x;
            synthl[idx] += (synthl[idx - 1] + synthl[idx + 1] + 2) >> 2;
        }
        synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;
    } else if (width == 1) {
        synthl[0] += (synthl[1] + 1) >> 1;
    }
    synthl += synth_width;
}
}
