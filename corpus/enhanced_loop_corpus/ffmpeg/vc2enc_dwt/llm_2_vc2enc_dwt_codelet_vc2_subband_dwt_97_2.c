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
    dwtcoef *base = synthl;
    base[1] -= (8 * base[0] + 9 * base[2] - base[4] + 8) >> 4;
    for (x = 1; x < width - 2; x++) {
        ptrdiff_t idx = 2 * x;
        base[idx + 1] -= (9 * base[idx] + 9 * base[idx + 2] - base[idx + 4] - base[idx - 2] + 8) >> 4;
    }
    base[synth_width - 1] -= (17 * base[synth_width - 2] - base[synth_width - 4] + 8) >> 4;
    base[synth_width - 3] -= (8 * base[synth_width - 2] + 9 * base[synth_width - 4] - base[synth_width - 6] + 8) >> 4;
    base[0] += (base[1] + base[1] + 2) >> 2;
    for (x = 1; x < width - 1; x++) {
        ptrdiff_t idx = 2 * x;
        base[idx] += (base[idx - 1] + base[idx + 1] + 2) >> 2;
    }
    base[synth_width - 2] += (base[synth_width - 3] + base[synth_width - 1] + 2) >> 2;
    synthl += synth_width;
}
}
