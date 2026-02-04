#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern int x;
extern int y;
extern dwtcoef *datal;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y++) {
    ptrdiff_t base_synth = y * synth_width;
    ptrdiff_t base_data = y * stride;
    for (x = 0; x < synth_width; x++) {
        synthl[base_synth + x] = datal[base_data + x] * 2;
    }
}
}
