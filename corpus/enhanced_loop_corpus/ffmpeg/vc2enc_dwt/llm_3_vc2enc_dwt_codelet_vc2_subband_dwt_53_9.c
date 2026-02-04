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
for (y = 0; y < synth_height; y++) {
    dwtcoef *synth_row = &synthl[y * synth_width];
    dwtcoef *data_row = &datal[y * stride];
    for (x = 0; x < synth_width; x += 4) {
        synth_row[x]     = data_row[x]     << 1;
        if (x + 1 < synth_width) synth_row[x + 1] = data_row[x + 1] << 1;
        if (x + 2 < synth_width) synth_row[x + 2] = data_row[x + 2] << 1;
        if (x + 3 < synth_width) synth_row[x + 3] = data_row[x + 3] << 1;
    }
}
}
