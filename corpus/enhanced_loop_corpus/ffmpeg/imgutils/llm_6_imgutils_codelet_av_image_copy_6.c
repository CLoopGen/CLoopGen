#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesizes[4];
extern  int src_linesizes[4];
extern ptrdiff_t dst_linesizes1[4];
extern ptrdiff_t src_linesizes1[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t temp_dst[4], temp_src[4];
    for (i = 0; i < 4; i++) {
        temp_dst[i] = dst_linesizes[i];
        temp_src[i] = src_linesizes[i];
    }
    for (i = 0; i < 4; i++) {
        dst_linesizes1[i] = temp_dst[i];
        src_linesizes1[i] = temp_src[i];
    }
}
