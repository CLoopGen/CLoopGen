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
    int64_t local_index2 = index2;
    for (dst_index = 0; dst_index < dst_size; dst_index++) {
        dst[dst_index] = src[local_index2 >> 32];
        local_index2 += incr;
    }
    index2 = local_index2;
}
