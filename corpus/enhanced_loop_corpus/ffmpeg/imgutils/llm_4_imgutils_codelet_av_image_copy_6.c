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
    for (i = 0; i < 4; i++) {
        if (dst_linesizes[i] >= 0) {
            dst_linesizes1[i] = dst_linesizes[i];
        }
        if (src_linesizes[i] >= 0) {
            src_linesizes1[i] = src_linesizes[i];
        }
    }
}
