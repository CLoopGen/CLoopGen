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
    dwtcoef temp1 = synthl[0];
    dwtcoef temp2 = synthl[2];
    dwtcoef temp4 = synthl[4];
    synthl[1] -= (8 * temp1 + 9 * temp2 - temp4 + 8) >> 4;
    for (x = 1; x < width - 2; x++) {
        dwtcoef left = synthl[2 * x - 2];
        dwtcoef mid1 = synthl[2 * x];
        dwtcoef mid2 = synthl[2 * x + 2];
        dwtcoef right = synthl[2 * x + 4];
        synthl[2 * x + 1] -= (9 * mid1 + 9 * mid2 - right - left + 8) >> 4;
    }
    dwtcoef w1 = synthl[synth_width - 6];
    dwtcoef w2 = synthl[synth_width - 4];
    dwtcoef w3 = synthl[synth_width - 2];
    synthl[synth_width - 1] -= (17 * w3 - w2 + 8) >> 4;
    synthl[synth_width - 3] -= (8 * w3 + 9 * w2 - w1 + 8) >> 4;
    dwtcoef s1 = synthl[1];
    synthl[0] += (s1 + s1 + 2) >> 2;
    for (x = 1; x < width - 1; x++) {
        dwtcoef prev = synthl[2 * x - 1];
        dwtcoef next = synthl[2 * x + 1];
        synthl[2 * x] += (prev + next + 2) >> 2;
    }
    dwtcoef last_prev = synthl[synth_width - 3];
    dwtcoef last_curr = synthl[synth_width - 1];
    synthl[synth_width - 2] += (last_prev + last_curr + 2) >> 2;
    synthl += synth_width;
}
}
