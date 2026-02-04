#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_accum[64]; // Local accumulation to remove direct WAW and WAR hazards
    for (y = 0; y < height + 7; y++) {
        // Unroll by 2 to break loop-carried dependencies and expose parallelism
        x = 0;
        for (; x <= width - 2; x += 2) {
            // Compute two independent outputs with no intra-loop iteration dependencies
            int16_t val0 = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + 
                            filter[2] * src[x - 1] + filter[3] * src[x] + 
                            filter[4] * src[x + 1] + filter[5] * src[x + 2] + 
                            filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 0;
            int16_t val1 = (filter[0] * src[x - 2] + filter[1] * src[x - 1] + 
                            filter[2] * src[x]     + filter[3] * src[x + 1] + 
                            filter[4] * src[x + 2] + filter[5] * src[x + 3] + 
                            filter[6] * src[x + 4] + filter[7] * src[x + 5]) >> 0;
            local_accum[x]   = val0;
            local_accum[x+1] = val1;
        }
        // Handle remainder
        for (; x < width; x++) {
            local_accum[x] = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + 
                              filter[2] * src[x - 1] + filter[3] * src[x] + 
                              filter[4] * src[x + 1] + filter[5] * src[x + 2] + 
                              filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 0;
        }
        // Copy local results to tmp without interference
        for (x = 0; x < width; x++) {
            tmp[x] = local_accum[x];
        }
        src += srcstride;
        tmp += 64;
    }
}
