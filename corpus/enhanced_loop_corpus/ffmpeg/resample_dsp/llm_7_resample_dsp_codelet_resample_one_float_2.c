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
    int64_t local_index2 = index2;
    float *local_dst = dst + dst_index;
    const int64_t local_incr = incr;
    for (int i = 0; i < dst_size; i++) {
        local_dst[i] = src[local_index2 >> 32];
        local_index2 += local_incr;
    }
    index2 = local_index2;
    dst_index = dst_size;
}
