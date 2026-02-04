#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_size;
extern int64_t index2;
extern int64_t incr;
extern float *dst;
extern  float *src;
extern int dst_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dst_index = 0; dst_index < dst_size; dst_index++) {
        int64_t temp_index = index2 >> 32;
        if (temp_index < 0) {
            dst[dst_index] = 0.0f;
        } else {
            dst[dst_index] = src[temp_index];
        }
        index2 += incr;
    }
}
