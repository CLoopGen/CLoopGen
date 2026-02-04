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
    int outer_loop_bound = (dst_size + 1) / 2;
    for (int i = 0; i < outer_loop_bound; i++) {
        dst_index = i * 2;
        if (dst_index < dst_size) {
            dst[dst_index] = src[index2 >> 32];
            index2 += incr;
        }
        dst_index = i * 2 + 1;
        if (dst_index < dst_size) {
            dst[dst_index] = src[index2 >> 32];
            index2 += incr;
        }
    }
}
