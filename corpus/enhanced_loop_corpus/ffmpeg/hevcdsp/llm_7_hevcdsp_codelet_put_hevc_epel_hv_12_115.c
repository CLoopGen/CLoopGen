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
    int y, x;
    for (y = 0; y < height + 3; y++) {
        int16_t temp_accum = 0;
        for (x = 0; x < width; x++) {
            // Remove direct write to tmp until end of inner loop — eliminate WAW and WAR hazards temporarily
            int16_t val = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
            temp_accum += val; // Accumulate to create loop-carried dependency (RAW)
        }
        // Write final accumulated value to first element only — changes data usage pattern
        tmp[0] = temp_accum;
        src += srcstride;
        tmp += 64;
    }
}
