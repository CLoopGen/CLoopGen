#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_size;
extern int64_t index2;
extern int64_t incr;
extern double *dst;
extern  double *src;
extern int dst_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dst_index = 0; dst_index < dst_size; dst_index += 2) { // Increased trip step to reduce iterations
        int64_t idx1 = index2 >> 32;
        int64_t idx2 = (index2 + incr) >> 32;
        dst[dst_index] = src[idx1];
        if (dst_index + 1 < dst_size) {
            dst[dst_index + 1] = src[idx2];
        }
        index2 += incr * 2; // Adjust increment to match step size
    }
}
