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
    const int min_width_needed = 7;
    if (width >= min_width_needed) {
        synthl[1] -= (8 * synthl[0] + 9 * synthl[2] - synthl[4] + 8) >> 4;
        for (x = 1; x < width - 2; x++)
            synthl[2 * x + 1] -= (9 * synthl[2 * x] + 9 * synthl[2 * x + 2] - synthl[2 * x + 4] - synthl[2 * x - 2] + 8) >> 4;
        synthl[synth_width - 1] -= (17 * synthl[synth_width - 2] - synthl[synth_width - 4] + 8) >> 4;
        synthl[synth_width - 3] -= (8 * synthl[synth_width - 2] + 9 * synthl[synth_width - 4] - synthl[synth_width - 6] + 8) >> 4;
        synthl[0] += (synthl[1] + synthl[1] + 2) >> 2;
        for (x = 1; x < width - 1; x++)
            synthl[2 * x] += (synthl[2 * x - 1] + synthl[2 * x + 1] + 2) >> 2;
        synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;
    } else {
        // Fallback: minimal update when width is too small
        if (width == 3) {
            synthl[1] -= (8 * synthl[0] + 9 * synthl[2] + 8) >> 4;
            synthl[0] += (2 * synthl[1] + 2) >> 2;
        } else if (width >= 2) {
            synthl[0] += (2 * synthl[1] + 2) >> 2;
            synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;
        }
    }
    synthl += synth_width;
}
}
