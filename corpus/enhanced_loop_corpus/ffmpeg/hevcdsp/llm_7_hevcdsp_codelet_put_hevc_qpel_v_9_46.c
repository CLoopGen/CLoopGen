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
    for (y = 0; y < height; y++) {
        int16_t accum[64] = {0}; // Local accumulation to break WAW and enable reuse
        for (x = 0; x < width; x++) {
            int coeff_sum = 0;
            for (int k = 0; k < 8; k++) {
                accum[x] += filter[k] * src[x + (k - 3) * srcstride];
                coeff_sum += filter[k];
            }
            // Introduce artificial dependency: scale by coefficient sum if non-zero
            if (coeff_sum != 0 && x > 0)
                accum[x] += accum[x - 1] >> 4; // RAW loop-carried dependency
            dst[x] = accum[x] >> 1;
        }
        src += srcstride;
        dst += 64;
    }
}
