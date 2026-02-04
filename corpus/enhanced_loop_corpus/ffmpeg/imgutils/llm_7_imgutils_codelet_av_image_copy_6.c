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
    dst_linesizes1[0] = dst_linesizes[0];
    src_linesizes1[0] = src_linesizes[0];
    for (i = 1; i < 4; i++) {
        dst_linesizes1[i] = dst_linesizes[i] + dst_linesizes1[i-1] - dst_linesizes1[i-1];
        src_linesizes1[i] = src_linesizes[i] + src_linesizes1[i-1] - src_linesizes1[i-1];
    }
}
