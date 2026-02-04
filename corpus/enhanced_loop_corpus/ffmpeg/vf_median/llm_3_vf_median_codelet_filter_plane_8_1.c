#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify the original access pattern to use a strided iteration over 'i' to promote cache locality 
    // and reduce immediate reuse, simulating blocked or tiled behavior with stride unrolling

    int shift = (8 + 1) / 2;
    int scale = 1 << shift;
    int radius_val = radiusV + 1;
    int stride = 4;  // Process every 4th element first, then next lane
    uint8_t *src = srcp;
    uint16_t *fine = cfine;
    uint16_t *coarse = ccoarse;
    int w = width;

    // Unroll loop with stride-4 access pattern
    for (int s = 0; s < stride; s++) {
        for (int i = s; i < w; i += stride) {
            uint8_t val = src[i];
            int low = val & (scale - 1);
            int high = val >> shift;
            int fine_index = scale * (w * high + i) + low;
            int coarse_index = scale * i + high;

            fine[fine_index] += radius_val;
            coarse[coarse_index] += radius_val;
        }
    }
}
