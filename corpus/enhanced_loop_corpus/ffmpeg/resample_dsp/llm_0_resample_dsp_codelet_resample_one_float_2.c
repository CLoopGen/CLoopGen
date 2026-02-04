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
    int outer_loop_bound = (dst_size + 1) / 2;
    for (int i = 0; i < outer_loop_bound; i++) {
        int j1 = i * 2;
        if (j1 < dst_size) {
            dst[j1] = src[index2 >> 32];
            index2 += incr;
        }
        int j2 = i * 2 + 1;
        if (j2 < dst_size) {
            dst[j2] = src[index2 >> 32];
            index2 += incr;
        }
    }
}
