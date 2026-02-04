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
    // Variant 2: Strided memory access with step size of 2
    // Write to every second element first, then fill in gaps if needed
    // This modifies access pattern to be non-consecutive
    uint16_t fill_val = bufp[end_x - 1];
    // First pass: strided access with stride 2
    for (x = end_x; x < block_w; x += 2) {
        bufp[x] = fill_val;
    }
    // Second pass: fill remaining odd/even indices
    for (x = end_x + 1; x < block_w; x += 2) {
        bufp[x] = fill_val;
    }
}
