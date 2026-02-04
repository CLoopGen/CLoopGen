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
for (y = 1; y < height - 1; y += 2) {
    for (x = 0; x < synth_width; x++) {
        synthl[x + synth_width] -= (synthl[x] + 1) >> 1;
        if (y + 1 < height - 1) {
            synthl[x + synth_width * 3] -= (synthl[x + synth_width * 2] + 1) >> 1;
        }
    }
    synthl += (synth_width << 2);
}
}
