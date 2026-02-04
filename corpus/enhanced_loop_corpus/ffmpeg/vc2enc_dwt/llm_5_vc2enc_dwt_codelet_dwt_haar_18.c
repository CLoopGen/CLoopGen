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
        dwtcoef val, neighbor;
        ptrdiff_t idx_current = y * synth_width + x;
        ptrdiff_t idx_next = (y + 1) * synth_width + x;

        if (idx_next >= synth_width * synth_height) continue;

        val = synthl[idx_current];
        neighbor = synthl[idx_next];

        neighbor = neighbor - val;
        synthl[idx_next] = neighbor;
        synthl[idx_current] = val + ((neighbor + 1) >> 1);
    }
}
}
