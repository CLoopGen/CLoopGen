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
    int step = 4;
    for (dst_index = 0; dst_index < dst_size; dst_index++) {
        int64_t temp_index = index2 >> 32;
        dst[dst_index] = (src[temp_index] + src[(temp_index + 1) % (dst_size + 1)]) * 0.5f;
        index2 += incr;
        if ((dst_index % step) == 0) {
            dst[dst_index] *= 2.0f;
        }
    }
}
