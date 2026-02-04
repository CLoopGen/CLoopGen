#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v;
extern  int *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with restructured indexing
    // Instead of accessing src with decreasing and strided pattern (63 - 2*i, etc.),
    // we precompute a temporary array or reorder access to be more sequential.
    // Here, we simulate a transformed access by flipping the iteration order
    // and using forward strides for better locality.

    int j;
    for (j = 0; j < 32; j++) {
        int idx_src1 = 63 - 2 * (31 - j); // Reverse i to get increasing src access
        int idx_src2 = 63 - 2 * (31 - j) - 1;
        int idx_v1 = 31 - j;
        int idx_v2 = 63 - (31 - j);

        v[idx_v1] = (int)(16U + src[idx_src1]) >> 5;
        v[idx_v2] = (int)(16U - src[idx_src2]) >> 5;
    }
}
