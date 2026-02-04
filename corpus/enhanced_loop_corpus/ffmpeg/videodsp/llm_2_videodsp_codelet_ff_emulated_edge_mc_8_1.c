#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_w;
extern int x;
extern int end_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward copy from a fixed source
    int start = end_x - 1;
    for (x = end_x; x < block_w; x += 2) {
        if (start >= 0) {
            bufp[x] = bufp[start];
        }
        if (x + 1 < block_w && start >= 0) {
            bufp[x + 1] = bufp[start];
        }
    }
}
