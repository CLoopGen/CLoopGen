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
    dwtcoef val0 = synthl[0];
    dwtcoef val1 = synthl[1];
    dwtcoef val2 = synthl[2];
    dwtcoef val4 = synthl[4];
    dwtcoef update1 = (8 * val0 + 9 * val2 - val4 + 8) >> 4;
    synthl[1] -= update1;

    dwtcoef updates[1024]; 
    int update_count = 0;
    for (x = 1; x < width - 2; x++) {
        dwtcoef a = synthl[2 * x];
        dwtcoef b = synthl[2 * x + 2];
        dwtcoef c = synthl[2 * x + 4];
        dwtcoef d = synthl[2 * x - 2];
        updates[update_count++] = (9 * a + 9 * b - c - d + 8) >> 4;
    }
    for (x = 1; x < width - 2; x++) {
        synthl[2 * x + 1] -= updates[x - 1];
    }

    dwtcoef w_m6 = synthl[synth_width - 6];
    dwtcoef w_m4 = synthl[synth_width - 4];
    dwtcoef w_m2 = synthl[synth_width - 2];
    dwtcoef w_m1 = synthl[synth_width - 1];
    dwtcoef w_m3 = synthl[synth_width - 3];

    synthl[synth_width - 1] -= (17 * w_m2 - w_m4 + 8) >> 4;
    synthl[synth_width - 3] -= (8 * w_m2 + 9 * w_m4 - w_m6 + 8) >> 4;

    synthl[0] += (val1 + val1 + 2) >> 2;

    for (x = 1; x < width - 1; x++) {
        dwtcoef left_odd = synthl[2 * x - 1];
        dwtcoef right_odd = synthl[2 * x + 1];
        synthl[2 * x] += (left_odd + right_odd + 2) >> 2;
    }

    synthl[synth_width - 2] += (w_m3 + w_m1 + 2) >> 2;

    synthl += synth_width;
}
}
