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
    int16_t *base_ptr = dataptr;
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        int16_t d0 = base_ptr[0], d1 = base_ptr[1], d2 = base_ptr[2], d3 = base_ptr[3];
        int16_t d4 = base_ptr[4], d5 = base_ptr[5], d6 = base_ptr[6], d7 = base_ptr[7];

        tmp0 = d0 + d7;
        tmp7 = d0 - d7;
        tmp1 = d1 + d6;
        tmp6 = d1 - d6;
        tmp2 = d2 + d5;
        tmp5 = d2 - d5;
        tmp3 = d3 + d4;
        tmp4 = d3 - d4;

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        base_ptr[0] = (int16_t)(tmp10 + tmp11);
        base_ptr[4] = (int16_t)(tmp10 - tmp11);

        z1 = (int16_t)((((tmp12 + tmp13) * 181) + 128) >> 8);
        base_ptr[2] = tmp13 + z1;
        base_ptr[6] = tmp13 - z1;

        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;

        z5 = (int16_t)((((tmp10 - tmp12) * 98) + 128) >> 8);
        z2 = (int16_t)(((tmp10 * 139) + 128) >> 8) + z5;
        z4 = (int16_t)(((tmp12 * 334) + 128) >> 8) + z5;
        z3 = (int16_t)(((tmp11 * 181) + 128) >> 8);

        z11 = tmp7 + z3;
        z13 = tmp7 - z3;

        base_ptr[5] = z13 + z2;
        base_ptr[3] = z13 - z2;
        base_ptr[1] = z11 + z4;
        base_ptr[7] = z11 - z4;

        base_ptr += 8;
    }
    dataptr = base_ptr;
}
