#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp0;
extern int tmp1;
extern int tmp2;
extern int tmp3;
extern int tmp4;
extern int tmp5;
extern int tmp6;
extern int tmp7;
extern int tmp10;
extern int tmp11;
extern int tmp12;
extern int tmp13;
extern int z1;
extern int z2;
extern int z3;
extern int z4;
extern int z5;
extern int z11;
extern int z13;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing elements with stride 8 (i.e., dataptr[8*k]), 
    // reorganize to operate on a local array that holds consecutive values.
    // We assume dataptr points to the start of an 8-element int16_t block, and we process each row consecutively.

    int16_t local[8];
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Load data with base offset: treat dataptr as pointing to blocks of 8 consecutive int16_t
        for (int i = 0; i < 8; i++) {
            local[i] = dataptr[i];  // Consecutive access instead of strided
        }

        tmp0 = local[0] + local[7];
        tmp7 = local[0] - local[7];
        tmp1 = local[1] + local[6];
        tmp6 = local[1] - local[6];
        tmp2 = local[2] + local[5];
        tmp5 = local[2] - local[5];
        tmp3 = local[3] + local[4];
        tmp4 = local[3] - local[4];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        local[0] = tmp10 + tmp11;
        local[4] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * (((int32_t)181))) >> (8)));
        local[2] = tmp13 + z1;
        local[6] = tmp13 - z1;
        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;
        z5 = ((int16_t)(((tmp10 - tmp12) * (((int32_t)98))) >> (8)));
        z2 = ((int16_t)(((tmp10) * (((int32_t)139))) >> (8))) + z5;
        z4 = ((int16_t)(((tmp12) * (((int32_t)334))) >> (8))) + z5;
        z3 = ((int16_t)(((tmp11) * (((int32_t)181))) >> (8)));
        z11 = tmp7 + z3;
        z13 = tmp7 - z3;
        local[5] = z13 + z2;
        local[3] = z13 - z2;
        local[1] = z11 + z4;
        local[7] = z11 - z4;

        // Write back results consecutively
        for (int i = 0; i < 8; i++) {
            dataptr[i] = local[i];
        }
        dataptr += 8; // Move to next 8-element block
    }
}
