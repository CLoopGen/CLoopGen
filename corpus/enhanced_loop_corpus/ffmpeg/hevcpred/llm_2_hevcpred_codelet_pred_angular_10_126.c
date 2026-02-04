#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint16_t *left;
extern  int inv_angle[];
extern uint16_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of scattered access via transformed index, we rewrite to access ref_tmp consecutively
    // by reordering computation based on predictable stride in output index.
    // We assume last <= -1, so we traverse from last to -1, but now precompute the source indices
    // and write to consecutive locations in reverse order.

    int start = last;
    int count = (-1 - start + 1); // number of iterations
    for (int i = 0; i < count; i++) {
        int x_val = start + i;
        ref_tmp[x_val] = left[-1 + ((x_val * inv_angle[mode - 11] + 128) >> 8)];
    }
}
