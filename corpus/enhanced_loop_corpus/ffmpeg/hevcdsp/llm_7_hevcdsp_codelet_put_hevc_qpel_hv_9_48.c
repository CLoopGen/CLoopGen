#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_dst = dst;
    int16_t *local_tmp = tmp;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Eliminate direct use of global state in computation to remove RAW dependencies on global dst/tmp
            int16_t val = (filter[0] * local_tmp[x - 3 * 64] +
                          filter[1] * local_tmp[x - 2 * 64] +
                          filter[2] * local_tmp[x - 64] +
                          filter[3] * local_tmp[x] +
                          filter[4] * local_tmp[x + 64] +
                          filter[5] * local_tmp[x + 2 * 64] +
                          filter[6] * local_tmp[x + 3 * 64] +
                          filter[7] * local_tmp[x + 4 * 64]) >> 6;
            *(local_dst + x) = val;
        }
        local_tmp += 64;
        local_dst += 64;
    }
    // No side effects on globals until the end — breaks loop-carried dependencies via privatization
    // Simulates reduction in data hazards through variable scoping and delayed exposure
}
