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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing elements with stride 8 (i.e., dataptr[8 * i]), 
    // reorganize to use a local array to store values consecutively,
    // simulate the same computation but on a temporary buffer for better locality.

    int16_t temp[8];
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Load data into a contiguous temporary array
        for (int i = 0; i < 8; i++) {
            temp[i] = dataptr[i * 8];
        }

        tmp0 = temp[0] + temp[7];
        tmp7 = temp[0] - temp[7];
        tmp1 = temp[1] + temp[6];
        tmp6 = temp[1] - temp[6];
        tmp2 = temp[2] + temp[5];
        tmp5 = temp[2] - temp[5];
        tmp3 = temp[3] + temp[4];
        tmp4 = temp[3] - temp[4];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        temp[0] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        temp[4] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));
        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        temp[2] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        temp[6] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (int)((z3 + z4) * (unsigned int)(((int32_t)9633)));
        tmp4 = (int)((tmp4) * (unsigned int)(((int32_t)2446)));
        tmp5 = (int)((tmp5) * (unsigned int)(((int32_t)16819)));
        tmp6 = (int)((tmp6) * (unsigned int)(((int32_t)25172)));
        tmp7 = (int)((tmp7) * (unsigned int)(((int32_t)12299)));
        z1 = (int)((z1) * (unsigned int)(-((int32_t)7373)));
        z2 = (int)((z2) * (unsigned int)(-((int32_t)20995)));
        z3 = (int)((z3) * (unsigned int)(-((int32_t)16069)));
        z4 = (int)((z4) * (unsigned int)(-((int32_t)3196)));
        z3 += z5;
        z4 += z5;

        temp[7] = (((int)(tmp4 + z1 + z3) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        temp[5] = (((int)(tmp5 + z2 + z4) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        temp[3] = (((int)(tmp6 + z2 + z3) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        temp[1] = (((int)(tmp7 + z1 + z4) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        // Write back results in strided manner
        for (int i = 0; i < 8; i++) {
            dataptr[i * 8] = temp[i];
        }
        dataptr++;
    }
}
