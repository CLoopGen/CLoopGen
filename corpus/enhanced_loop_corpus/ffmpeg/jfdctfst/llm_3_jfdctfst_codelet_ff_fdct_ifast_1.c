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
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Use an index array to access dataptr elements indirectly.
    // This simulates scenarios where access patterns are data-dependent or non-uniform.

    const int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Logical indices, could be reordered or modified
    int16_t *base = dataptr; // Save base pointer

    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        tmp0 = base[indices[0]*8] + base[indices[7]*8];
        tmp7 = base[indices[0]*8] - base[indices[7]*8];
        tmp1 = base[indices[1]*8] + base[indices[6]*8];
        tmp6 = base[indices[1]*8] - base[indices[6]*8];
        tmp2 = base[indices[2]*8] + base[indices[5]*8];
        tmp5 = base[indices[2]*8] - base[indices[5]*8];
        tmp3 = base[indices[3]*8] + base[indices[4]*8];
        tmp4 = base[indices[3]*8] - base[indices[4]*8];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        base[indices[0]*8] = tmp10 + tmp11;
        base[indices[4]*8] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * (((int32_t)181))) >> (8)));
        base[indices[2]*8] = tmp13 + z1;
        base[indices[6]*8] = tmp13 - z1;
        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;
        z5 = ((int16_t)(((tmp10 - tmp12) * (((int32_t)98))) >> (8)));
        z2 = ((int16_t)(((tmp10) * (((int32_t)139))) >> (8))) + z5;
        z4 = ((int16_t)(((tmp12) * (((int32_t)334))) >> (8))) + z5;
        z3 = ((int16_t)(((tmp11) * (((int32_t)181))) >> (8)));
        z11 = tmp7 + z3;
        z13 = tmp7 - z3;
        base[indices[5]*8] = z13 + z2;
        base[indices[3]*8] = z13 - z2;
        base[indices[1]*8] = z11 + z4;
        base[indices[7]*8] = z11 - z4;
        base++; // Increment base pointer for next iteration
    }
}
