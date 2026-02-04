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
extern unsigned int z1;
extern unsigned int z2;
extern unsigned int z3;
extern unsigned int z4;
extern unsigned int z5;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 4 - 1; ctr >= 0; ctr--) {
        // Reduced arithmetic: precompute common terms and eliminate redundant operations
        tmp0 = dataptr[0] + dataptr[7];
        tmp7 = dataptr[0] - dataptr[7];
        tmp1 = dataptr[1] + dataptr[6];
        tmp6 = dataptr[1] - dataptr[6];
        tmp2 = dataptr[2] + dataptr[5];
        tmp5 = dataptr[2] - dataptr[5];
        tmp3 = dataptr[3] + dataptr[4];
        tmp4 = dataptr[3] - dataptr[4];

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        dataptr[0] = (int16_t)((tmp10 + tmp11) * (1 << 4));
        dataptr[4] = (int16_t)((tmp10 - tmp11) * (1 << 4));

        // Merge multiplications with constants into a single expression where possible
        int term1 = (tmp12 + tmp13) * 4433;
        int term2 = tmp13 * 6270;
        int term3 = tmp12 * (-15137);
        dataptr[2] = (int16_t)(((term1 + term2) + (1 << 8)) >> 9);
        dataptr[6] = (int16_t)(((term1 + term3) + (1 << 8)) >> 9);

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (z3 + z4) * 9633;

        // Apply scaling directly in final computation to reduce temp variables
        dataptr[7] = (int16_t)((((tmp4 * 2446) + (z1 * -7373) + (z3 * -16069) + z5) + (1 << 8)) >> 9);
        dataptr[5] = (int16_t)((((tmp5 * 16819) + (z2 * -20995) + (z4 * -3196) + z5) + (1 << 8)) >> 9);
        dataptr[3] = (int16_t)((((tmp6 * 25172) + (z2 * -20995) + (z3 * -16069) + z5) + (1 << 8)) >> 9);
        dataptr[1] = (int16_t)((((tmp7 * 12299) + (z1 * -7373) + (z4 * -3196) + z5) + (1 << 8)) >> 9);

        dataptr += 8;
    }
}
