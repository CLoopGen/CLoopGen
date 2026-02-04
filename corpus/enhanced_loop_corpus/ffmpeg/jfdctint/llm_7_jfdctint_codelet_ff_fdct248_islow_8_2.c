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
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Eliminate some intermediate variables to reduce WAW hazards and flatten dependencies
        int sum01 = dataptr[8 * 0] + dataptr[8 * 1];
        int sum23 = dataptr[8 * 2] + dataptr[8 * 3];
        int sum45 = dataptr[8 * 4] + dataptr[8 * 5];
        int sum67 = dataptr[8 * 6] + dataptr[8 * 7];
        int diff01 = dataptr[8 * 0] - dataptr[8 * 1];
        int diff23 = dataptr[8 * 2] - dataptr[8 * 3];
        int diff45 = dataptr[8 * 4] - dataptr[8 * 5];
        int diff67 = dataptr[8 * 6] - dataptr[8 * 7];

        // Remove loop-carried dependency by precomputing all values before any store
        int sum_sum = sum01 + sum67;
        int sum_diff = sum23 + sum45;
        int diff_sum = sum23 - sum45;
        int diff_diff = sum01 - sum67;

        // Direct assignment without reusing tmp variables — eliminates WAW
        dataptr[8 * 0] = (((int)(sum_sum + sum_diff) + (1 << ((4) - 1))) >> (4));
        dataptr[8 * 4] = (((int)(sum_sum - sum_diff) + (1 << ((4) - 1))) >> (4));

        int z1_a = (int)((diff_sum + diff_diff) * (unsigned int)(((int32_t)4433)));
        dataptr[8 * 2] = (((int)(z1_a + (int)(diff_diff * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr[8 * 6] = (((int)(z1_a + (int)(diff_sum * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        int sum01_2 = diff01 + diff67;
        int sum23_2 = diff23 + diff45;
        int diff23_2 = diff23 - diff45;
        int diff01_2 = diff01 - diff67;

        dataptr[8 * 1] = (((int)(sum01_2 + sum23_2) + (1 << ((4) - 1))) >> (4));
        dataptr[8 * 5] = (((int)(sum01_2 - sum23_2) + (1 << ((4) - 1))) >> (4));

        int z1_b = (int)((diff23_2 + diff01_2) * (unsigned int)(((int32_t)4433)));
        dataptr[8 * 3] = (((int)(z1_b + (int)(diff01_2 * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr[8 * 7] = (((int)(z1_b + (int)(diff23_2 * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        // No reuse of tmp* globals — breaks all inter-statement dependencies via local isolation
        dataptr++;
    }
}
