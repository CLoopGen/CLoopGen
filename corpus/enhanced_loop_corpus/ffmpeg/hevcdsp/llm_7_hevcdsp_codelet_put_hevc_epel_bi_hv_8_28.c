#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_cache[4] = {0}; // Local state to break dependencies
    for (y = 0; y < height + 3; y++) {
        // Unroll by 2 and eliminate write-after-write on tmp via independent accumulators
        for (x = 0; x + 1 < width; x += 2) {
            local_cache[0] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 8;
            local_cache[1] = (filter[0] * src[x] + filter[1] * src[x + 1] + filter[2] * src[x + 2] + filter[3] * src[x + 3]) >> 8;
            tmp[x]     = local_cache[0];
            tmp[x + 1] = local_cache[1];
        }
        // Handle leftover element without creating WAR hazard
        if (x < width) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
