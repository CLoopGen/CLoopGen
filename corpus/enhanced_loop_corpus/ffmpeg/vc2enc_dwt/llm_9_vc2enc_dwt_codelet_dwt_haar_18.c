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
    for (y = 0; y < synth_height; y++) {
        dwtcoef temp1, temp2;
        ptrdiff_t idx0 = y * synth_width + x;
        ptrdiff_t idx1 = (y + 1) * synth_width + x;
        if (x + 1 < synth_width && y + 1 < synth_height) {
            temp1 = synthl[idx1] - synthl[idx0];
            temp2 = synthl[idx1 + 1] - synthl[idx0 + 1];
            synthl[idx0] = synthl[idx0] + ((temp1 + 1) >> 1);
            synthl[idx0 + 1] = synthl[idx0 + 1] + ((temp2 + 1) >> 1);
            synthl[idx1] = temp1;
            synthl[idx1 + 1] = temp2;
        } else if (x + 1 >= synth_width && y + 1 < synth_height) {
            synthl[idx1] = synthl[idx1] - synthl[idx0];
            synthl[idx0] = synthl[idx0] + ((synthl[idx1] + 1) >> 1);
        }
    }
}
}
