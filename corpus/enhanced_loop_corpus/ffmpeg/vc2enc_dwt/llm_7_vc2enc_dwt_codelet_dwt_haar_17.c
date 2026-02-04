#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern ptrdiff_t stride;
extern  int s;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern dwtcoef *datal;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y++) {
    for (x = 0; x < synth_width; x += 2) {
        dwtcoef val_even = datal[y * stride + x] << s;
        dwtcoef val_odd = datal[y * stride + x + 1] << s;
        dwtcoef diff = val_odd - val_even;
        synthl[y * synth_width + x + 1] = diff;
        synthl[y * synth_width + x] = val_even + ((diff + 1) >> 1);
    }
}
}
