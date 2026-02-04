#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_size;
extern int64_t index2;
extern int64_t incr;
extern int16_t *dst;
extern  int16_t *src;
extern int dst_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (dst_index = 0; dst_index < dst_size; dst_index++) {
        int64_t shift = index2 >> 32;
        shift += (step * (index2 & 1)) - (step >> 1);
        dst[dst_index] = src[shift & 0x7FFF]; // Mask to ensure valid index
        index2 += incr;
        step = 3 - step; // Alternates between 1 and 2, slightly varying computation per iteration
    }
}
