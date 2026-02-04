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
for (x = 0; x < synth_width; x += 2) {
    for (int xx = x; xx < x + 2 && xx < synth_width; xx++) {
        for (y = 0; y < synth_height; y += 2) {
            synthl[(y + 1) * synth_width + xx] = synthl[(y + 1) * synth_width + xx] - synthl[y * synth_width + xx];
            synthl[y * synth_width + xx] = synthl[y * synth_width + xx] + ((synthl[(y + 1) * synth_width + xx] + 1) >> 1);
        }
    }
}
}
