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
    int16_t local_tmp[64]; // Remove direct write to output array in inner loop, eliminate WAW across iterations
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x += 4) { // Unroll by 4 to break sequential dependencies and expose parallelism
            local_tmp[x]     = (filter[0] * src[x - 1] + filter[1] * src[x]     + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 0;
            local_tmp[x + 1] = (filter[0] * src[x]     + filter[1] * src[x + 1] + filter[2] * src[x + 2] + filter[3] * src[x + 3]) >> 0;
            local_tmp[x + 2] = (filter[0] * src[x + 1] + filter[1] * src[x + 2] + filter[2] * src[x + 3] + filter[3] * src[x + 4]) >> 0;
            local_tmp[x + 3] = (filter[0] * src[x + 2] + filter[1] * src[x + 3] + filter[2] * src[x + 4] + filter[3] * src[x + 5]) >> 0;
        }
        for (x = 0; x < width; x++) {
            tmp[x] = local_tmp[x]; // Single write-back to eliminate loop-carried WAW
        }
        src += srcstride;
        tmp += 64;
    }
}
