#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed processing (access vertically first)
    // This variant processes multiple rows at once in a column-wise fashion with unrolled vertical taps
    int16_t *dst_col = dst;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint16_t val = 0;
            // Explicitly load the 8 vertical samples using fixed offsets from current (x,y)
            val += filter[0] * src[(y - 3) * srcstride + x];
            val += filter[1] * src[(y - 2) * srcstride + x];
            val += filter[2] * src[(y - 1) * srcstride + x];
            val += filter[3] * src[(y    ) * srcstride + x];
            val += filter[4] * src[(y + 1) * srcstride + x];
            val += filter[5] * src[(y + 2) * srcstride + x];
            val += filter[6] * src[(y + 3) * srcstride + x];
            val += filter[7] * src[(y + 4) * srcstride + x];
            dst_col[y * 64 + x] = val >> 2;
        }
    }
}
