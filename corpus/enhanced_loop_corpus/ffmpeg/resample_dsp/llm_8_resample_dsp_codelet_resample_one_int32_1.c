#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_size;
extern int64_t index2;
extern int64_t incr;
extern int32_t *dst;
extern  int32_t *src;
extern int dst_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dst_index = 0; dst_index < dst_size; dst_index += 2) {
        dst[dst_index] = src[index2 >> 32];
        index2 += incr;
        if (dst_index + 1 < dst_size) {
            dst[dst_index + 1] = src[(index2 + incr) >> 32];
        }
        index2 += incr;
    }
}
