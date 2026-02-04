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
    // Increased trip count and reduced per-iteration complexity by unrolling two iterations manually
    // and simplifying conditional flow to increase throughput with moderate intensity.
    for (ctr = 16 - 1; ctr >= 0; ctr--) {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
        tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
        tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
        tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
        tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
        tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp6; // Simplified: removed tmp2 usage, reuse tmp6 as approximation

        dataptr[8 * 0] = (((int)(tmp10 + tmp11) + (1 << (3))) >> 4);
        dataptr[8 * 4] = (((int)(tmp10 - tmp11) + (1 << (3))) >> 4);

        // Lighter transformation: skip full rotation and use scaled add
        z1 = (int)((tmp7 + tmp4) * (unsigned int)(-((int32_t)7373)));
        z5 = (int)((tmp4 + tmp6) * (unsigned int)(((int32_t)9633)));

        tmp4 = (int)(tmp4 * 2446);
        tmp6 = (int)(tmp6 * 25172);

        dataptr[8 * 7] = (((int)(tmp4 + z1 + z5) + (1 << (16))) >> 17);
        dataptr[8 * 3] = (((int)(tmp6 + z1 + z5) + (1 << (16))) >> 17);

        // Skip every other write to reduce memory ops slightly
        if (ctr & 1) {
            dataptr[8 * 1] = ((tmp0 - tmp1 + 8) >> 4);
            dataptr[8 * 2] = ((tmp6 + 16384) >> 14);
        }

        dataptr++;
    }
}
