#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int base_idx = 8 * i;
    ptrdiff_t addr_diff = stride * i;

    // Use indirect access via pointer arithmetic with precomputed offsets
    ptrdiff_t offsets[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int diffs[8];

    for (int j = 0; j < 8; j++) {
        ptrdiff_t offset = offsets[j];
        diffs[j] = (src[addr_diff + offset] - dst[addr_diff + offset]);
    }

    temp[base_idx + 0] = diffs[0] + diffs[1];
    temp[base_idx + 1] = diffs[0] - diffs[1];
    temp[base_idx + 2] = diffs[2] + diffs[3];
    temp[base_idx + 3] = diffs[2] - diffs[3];
    temp[base_idx + 4] = diffs[4] + diffs[5];
    temp[base_idx + 5] = diffs[4] - diffs[5];
    temp[base_idx + 6] = diffs[6] + diffs[7];
    temp[base_idx + 7] = diffs[6] - diffs[7];

    {
        int a = temp[base_idx + 0], b = temp[base_idx + 2];
        temp[base_idx + 0] = a + b;
        temp[base_idx + 2] = a - b;
    }
    {
        int a = temp[base_idx + 1], b = temp[base_idx + 3];
        temp[base_idx + 1] = a + b;
        temp[base_idx + 3] = a - b;
    }
    {
        int a = temp[base_idx + 4], b = temp[base_idx + 6];
        temp[base_idx + 4] = a + b;
        temp[base_idx + 6] = a - b;
    }
    {
        int a = temp[base_idx + 5], b = temp[base_idx + 7];
        temp[base_idx + 5] = a + b;
        temp[base_idx + 7] = a - b;
    }
    {
        int a = temp[base_idx + 0], b = temp[base_idx + 4];
        temp[base_idx + 0] = a + b;
        temp[base_idx + 4] = a - b;
    }
    {
        int a = temp[base_idx + 1], b = temp[base_idx + 5];
        temp[base_idx + 1] = a + b;
        temp[base_idx + 5] = a - b;
    }
    {
        int a = temp[base_idx + 2], b = temp[base_idx + 6];
        temp[base_idx + 2] = a + b;
        temp[base_idx + 6] = a - b;
    }
    {
        int a = temp[base_idx + 3], b = temp[base_idx + 7];
        temp[base_idx + 3] = a + b;
        temp[base_idx + 7] = a - b;
    }
}
}
