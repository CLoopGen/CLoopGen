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
    // Variant 2: Consecutive forward access on src starting from base index, decoupling from index2 shift addressing
    int64_t base_index = index2 >> 32;
    for (dst_index = 0; dst_index < dst_size; dst_index++) {
        // Access src consecutively from base_index onward
        dst[dst_index] = src[base_index + dst_index];
        index2 += incr; // Still update index2 to maintain state consistency
    }
}
