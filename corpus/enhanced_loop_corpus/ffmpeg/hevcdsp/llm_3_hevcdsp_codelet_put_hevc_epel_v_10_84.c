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
    // Variant 2: Strided memory access using pointer arithmetic with fixed offsets
    for (y = 0; y < height; y++) {
        const uint16_t *s = src;
        int16_t *d = dst;
        // Use precomputed offset array for non-consecutive access pattern
        ptrdiff_t offsets[4] = { -srcstride, 0, srcstride, 2*srcstride };
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += filter[k] * s[x + offsets[k]];
            }
            d[x] = (int16_t)(sum >> 2);
        }
        src += srcstride;
        dst += 64;
    }
}
