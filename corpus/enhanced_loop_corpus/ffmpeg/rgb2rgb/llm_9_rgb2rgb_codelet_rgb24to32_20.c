#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (i = 0; 9 * i < src_size; i += step) {
        int src_idx = 3 * i;
        int dst_idx = 4 * i;
        dst[dst_idx + 0] = (src_idx + 2 < src_size) ? src[src_idx + 2] : 0;
        dst[dst_idx + 1] = (src_idx + 1 < src_size) ? src[src_idx + 1] : 0;
        dst[dst_idx + 2] = (src_idx + 0 < src_size) ? src[src_idx + 0] : 0;
        dst[dst_idx + 3] = 255;
    }
}
