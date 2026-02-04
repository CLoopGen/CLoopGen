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
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int idx = i * 2 + j;
            dst_linesizes1[idx] = dst_linesizes[idx];
            src_linesizes1[idx] = src_linesizes[idx];
        }
    }
}
