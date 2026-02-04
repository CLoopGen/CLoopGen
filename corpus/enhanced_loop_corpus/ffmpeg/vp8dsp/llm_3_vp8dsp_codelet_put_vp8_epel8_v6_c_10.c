#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed processing order
    for (y = 0; y < h; y++) {
        // Process in reverse x order with strided coefficient access
        for (x = 7; x >= 0; x--) {
            int filtered_val = 0;
            const int offsets[] = { -2, -1, 0, 1, 2, 3 };
            // Access filter and src with consistent indexing but reversed output
            for (int k = 0; k < 6; k++) {
                int coeff = (k == 1 || k == 4) ? -filter[k] : filter[k];
                filtered_val += coeff * src[x + offsets[k] * srcstride];
            }
            dst[x] = cm[(filtered_val + 64) >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
