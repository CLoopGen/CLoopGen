#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < synth_width; x++) {
    for (y = 0; y < synth_height; y += 4) {
        if (y + 1 < synth_height) {
            synthl[(y + 1) * synth_width + x] = synthl[(y + 1) * synth_width + x] - synthl[y * synth_width + x];
            synthl[y * synth_width + x] = synthl[y * synth_width + x] + ((synthl[(y + 1) * synth_width + x] + 1) >> 1);
        }
        if (y + 3 < synth_height) {
            synthl[(y + 3) * synth_width + x] = synthl[(y + 3) * synth_width + x] - synthl[(y + 2) * synth_width + x];
            synthl[(y + 2) * synth_width + x] = synthl[(y + 2) * synth_width + x] + ((synthl[(y + 3) * synth_width + x] + 1) >> 1);
        }
    }
}
}
