#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *top;
extern uint8_t *left;
extern int x;
extern int ih;
extern int iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Rewriting index expressions to access top and left in increasing order only
    int indices[4] = {3, 4, 5, 6}; // Precomputed valid indices to allow consecutive pattern
    for (x = 0; x < 4; x++) {
        int forward_idx = indices[x];     // 3, 4, 5, 6
        int backward_idx = indices[3 - x]; // 6, 5, 4, 3
        ih += (x + 1) * (top[forward_idx] - top[backward_idx]);
        iv += (x + 1) * (left[forward_idx] - left[backward_idx]);
    }
}
