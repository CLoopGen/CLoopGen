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
    int outer_loop_bound = (dst_size + 15) / 16; // ceil(dst_size / 16)
    for (int i = 0; i < outer_loop_bound; i++) {
        for (int j = 0; j < 16; j++) {
            int dst_index = i * 16 + j;
            if (dst_index >= dst_size) break;
            dst[dst_index] = src[index2 >> 32];
            index2 += incr;
        }
    }
}
