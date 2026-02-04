#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_tmp = 0;
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            // Introduce loop-carried WAW and RAW dependency across x iterations
            // Current tmp[x] depends on previous iteration's result via 'prev_tmp'
            int16_t raw_src = (filter[0] * src[x - 1] + filter[1] * src[x] +
                               filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
            tmp[x] = raw_src + prev_tmp;  // WAW and RAW: current write depends on prior write via prev_tmp
            prev_tmp = raw_src;           // Update state for next iteration
        }
        // Reset dependency carrier at start of each row
        prev_tmp = 0;
        src += srcstride;
        tmp += 64;
    }
}
