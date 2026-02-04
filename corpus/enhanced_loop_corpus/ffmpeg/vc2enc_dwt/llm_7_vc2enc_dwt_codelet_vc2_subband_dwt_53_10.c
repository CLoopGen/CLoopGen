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
    dwtcoef *row = synthl;
    for (x = 1; x < width - 1; x++) {
        row[2 * x] += (row[2 * x - 1] + row[2 * x + 1] + 2) >> 2;
    }
    row[0] += (2 * row[1] + 2) >> 2;
    row[synth_width - 2] += (row[synth_width - 3] + row[synth_width - 1] + 2) >> 2;
    for (x = 0; x < width - 1; x++) {
        row[2 * x + 1] -= (row[2 * x] + row[2 * x + 2] + 1) >> 1;
    }
    row[synth_width - 1] -= (2 * row[synth_width - 2] + 1) >> 1;
    synthl += synth_width;
}
}
