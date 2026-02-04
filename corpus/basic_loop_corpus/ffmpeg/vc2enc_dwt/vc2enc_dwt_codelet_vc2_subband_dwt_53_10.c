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
    for (x = 0; x < width - 1; x++)
        synthl[2 * x + 1] -= (synthl[2 * x] + synthl[2 * x + 2] + 1) >> 1;
    synthl[synth_width - 1] -= (2 * synthl[synth_width - 2] + 1) >> 1;
    synthl[0] += (2 * synthl[1] + 2) >> 2;
    for (x = 1; x < width - 1; x++)
        synthl[2 * x] += (synthl[2 * x - 1] + synthl[2 * x + 1] + 2) >> 2;
    synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;
    synthl += synth_width;
}

}
