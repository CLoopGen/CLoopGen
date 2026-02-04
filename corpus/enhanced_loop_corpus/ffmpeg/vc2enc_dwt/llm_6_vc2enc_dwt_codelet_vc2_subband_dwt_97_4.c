#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int height;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dwtcoef *base = synthl;
    for (y = 1; y < height - 2; y++) {
        dwtcoef *row = base + y * (synth_width << 1);
        for (x = 0; x < synth_width; x++) {
            dwtcoef temp = (9 * row[x] + 9 * row[x + 2 * synth_width] - 
                            row[x - 2 * synth_width] - row[x + 4 * synth_width] + 8) >> 4;
            row[x + synth_width] -= temp;
        }
    }
}
