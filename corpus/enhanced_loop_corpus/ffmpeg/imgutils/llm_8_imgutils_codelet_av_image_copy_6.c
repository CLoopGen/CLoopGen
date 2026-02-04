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
    for (i = 0; i < 8; i += 2) {
        ptrdiff_t temp_dst = dst_linesizes[i/2];
        ptrdiff_t temp_src = src_linesizes[i/2];
        dst_linesizes1[i/2] = temp_dst;
        src_linesizes1[i/2] = temp_src;
    }
}
