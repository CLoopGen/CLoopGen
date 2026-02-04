#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern dwtcoef *datal;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y += 2) {
    for (x = 0; x < synth_width; x++) {
        if (y + 1 < synth_height) {
            synthl[x]                 = datal[x] << 1;
            synthl[synth_width + x]     = datal[stride + x] << 1;
        } else {
            synthl[x] = datal[x] << 1;
        }
    }
    synthl += 2 * synth_width;
    datal += 2 * stride;
}
}
