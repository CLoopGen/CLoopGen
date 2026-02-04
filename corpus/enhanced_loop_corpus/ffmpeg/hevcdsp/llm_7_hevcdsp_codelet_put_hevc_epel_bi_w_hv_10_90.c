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
    int16_t local_filter_sum = filter[0] + filter[1] + filter[2] + filter[3];
    for (y = 0; y < height + 3; y++) {
        // Eliminate loop-carried dependencies by unrolling and computing independent blocks
        x = 0;
        for (; x <= width - 4; x += 4) {
            tmp[x]     = ((filter[0] * src[x - 1] + filter[1] * src[x]     + filter[2] * src[x + 1]     + filter[3] * src[x + 2])     >> 2) * local_filter_sum;
            tmp[x + 1] = ((filter[0] * src[x]     + filter[1] * src[x + 1] + filter[2] * src[x + 2]     + filter[3] * src[x + 3])     >> 2) * local_filter_sum;
            tmp[x + 2] = ((filter[0] * src[x + 1] + filter[1] * src[x + 2] + filter[2] * src[x + 3]     + filter[3] * src[x + 4])     >> 2) * local_filter_sum;
            tmp[x + 3] = ((filter[0] * src[x + 2] + filter[1] * src[x + 3] + filter[2] * src[x + 4]     + filter[3] * src[x + 5])     >> 2) * local_filter_sum;
        }
        // Handle remaining elements without creating cross-iteration dependencies
        for (; x < width; x++) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 2;
        }
        src += srcstride;
        tmp += 64;
    }
}
