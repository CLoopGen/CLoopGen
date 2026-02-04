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



void loop() {
    // Variant 2: Strided memory access with step-through rows using array indexing and fixed offset strides
    ptrdiff_t stride = synth_width;
    for (y = 1; y < height - 1; y++) {
        ptrdiff_t center = y * stride;
        ptrdiff_t upper = (y - 1) * stride;
        ptrdiff_t lower = (y + 1) * stride;
        for (x = 0; x < synth_width; x++) {
            synthl[center + x] -= (synthl[upper + x] + synthl[lower + x] + 1) >> 1;
        }
    }
}
