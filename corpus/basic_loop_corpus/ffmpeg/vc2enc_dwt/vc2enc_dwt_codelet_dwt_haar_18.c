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
    for (y = 0; y < synth_height; y += 2) {
        synthl[(y + 1) * synth_width + x] = synthl[(y + 1) * synth_width + x] - synthl[y * synth_width + x];
        synthl[y * synth_width + x] = synthl[y * synth_width + x] + ((synthl[(y + 1) * synth_width + x] + 1) >> 1);
    }
}

}
