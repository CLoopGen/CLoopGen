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
    x = 0;
    if (synth_width > 0) {
        for (; x < synth_width - 1; x += 2) {
            synthl[y * synth_width + x + 1] = (datal[y * stride + x + 1] << s) - (datal[y * stride + x] << s);
            synthl[y * synth_width + x] = (datal[y * stride + x] << s) + ((synthl[y * synth_width + x + 1] + 1) >> 1);
        }
        if (x == synth_width - 1) {
            synthl[y * synth_width + x] = datal[y * stride + x] << s;
        }
    }
}
}
