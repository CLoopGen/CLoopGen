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
    // Variant 2: Consecutive read from src starting at base index, decoupling from index2 shift
    int64_t base_index = index2 >> 32;
    for (dst_index = 0; dst_index < dst_size; dst_index++) {
        dst[dst_index] = src[base_index + dst_index]; // Sequential forward access
    }
    // Update index2 as if all reads were done using initial offset and increment
    index2 += incr * dst_size;
}
