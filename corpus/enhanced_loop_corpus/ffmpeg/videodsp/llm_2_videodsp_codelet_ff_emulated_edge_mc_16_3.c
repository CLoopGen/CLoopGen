#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_w;
extern int x;
extern int end_x;
extern uint16_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal pattern
    // Instead of filling from end_x forward, fill backwards using consecutive assignment
    int start = end_x;
    for (x = block_w - 1; x >= start; x--) {
        bufp[x] = bufp[start - 1];
    }
}
