#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int k;
extern unsigned int j;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_dst = dst;
    int local_j = j;
    int local_width = width;
    ptrdiff_t local_stride = stride;
    for (k = 0; k < rlen; k++) {
        local_dst[local_j++] = 0;
        if (local_j == local_width) {
            local_j = 0;
            local_dst += local_stride;
        }
    }
    j = local_j;
    dst = local_dst;
}
