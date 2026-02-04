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
    for (int block_start = 0; block_start < dst_size; block_start += 4) {
        for (int offset = 0; offset < 4; offset++) {
            dst_index = block_start + offset;
            if (dst_index >= dst_size) break;
            dst[dst_index] = src[index2 >> 32];
            index2 += incr;
        }
    }
}
