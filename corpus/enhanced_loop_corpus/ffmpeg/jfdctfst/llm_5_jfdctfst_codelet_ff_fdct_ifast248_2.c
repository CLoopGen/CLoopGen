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
        // Eliminate some RAW dependencies by precomputing and storing in local temporaries with different order
        int t0 = dataptr[8 * 0], t1 = dataptr[8 * 1], t2 = dataptr[8 * 2], t3 = dataptr[8 * 3];
        int t4 = dataptr[8 * 4], t5 = dataptr[8 * 5], t6 = dataptr[8 * 6], t7 = dataptr[8 * 7];

        // Rearranged computation to break direct data flow and allow compiler more reordering freedom
        tmp4 = t0 - t1;
        tmp5 = t2 - t3;
        tmp6 = t4 - t5;
        tmp7 = t6 - t7;

        tmp0 = t0 + t1;
        tmp1 = t2 + t3;
        tmp2 = t4 + t5;
        tmp3 = t6 + t7;

        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;

        // Remove WAW hazard on dataptr stores by grouping writes at the end
        int out0 = tmp10 + tmp11;
        int out4 = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * 181) >> 8));
        int out2 = tmp13 + z1;
        int out6 = tmp13 - z1;

        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;

        int out1 = tmp10 + tmp11;
        int out5 = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * 181) >> 8));
        int out3 = tmp13 + z1;
        int out7 = tmp13 - z1;

        // All writes happen at the end — reduces intra-loop WAR/WAW hazards
        dataptr[8 * 0] = out0;
        dataptr[8 * 4] = out4;
        dataptr[8 * 2] = out2;
        dataptr[8 * 6] = out6;
        dataptr[8 * 1] = out1;
        dataptr[8 * 5] = out5;
        dataptr[8 * 3] = out3;
        dataptr[8 * 7] = out7;

        dataptr++;
    }
}
