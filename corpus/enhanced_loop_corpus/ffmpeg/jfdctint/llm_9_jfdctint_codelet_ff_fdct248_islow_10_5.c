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
    for (ctr = 4 - 1; ctr >= 0; ctr--) {
        // Unroll two iterations of the original arithmetic pattern
        // First half (original index 0,2,4,6)
        tmp0 = dataptr[0] + dataptr[8];
        tmp1 = dataptr[16] + dataptr[24];
        tmp2 = dataptr[32] + dataptr[40];
        tmp3 = dataptr[48] + dataptr[56];
        tmp4 = dataptr[0] - dataptr[8];
        tmp5 = dataptr[16] - dataptr[24];
        tmp6 = dataptr[32] - dataptr[40];
        tmp7 = dataptr[48] - dataptr[56];

        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;

        dataptr[0] = ((tmp10 + tmp11 + 2) >> 2);
        dataptr[32] = ((tmp10 - tmp11 + 2) >> 2);
        z1 = (tmp12 + tmp13) * 4433;
        dataptr[16] = (z1 + tmp13 * 6270 + (1 << 14)) >> 15;
        dataptr[48] = (z1 + tmp12 * (-15137) + (1 << 14)) >> 15;

        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;

        dataptr[8] = ((tmp10 + tmp11 + 2) >> 2);
        dataptr[40] = ((tmp10 - tmp11 + 2) >> 2);
        z1 = (tmp12 + tmp13) * 4433;
        dataptr[24] = (z1 + tmp13 * 6270 + (1 << 14)) >> 15;
        dataptr[56] = (z1 + tmp12 * (-15137) + (1 << 14)) >> 15;

        dataptr += 2; // Advance by two elements to simulate reduced trip count with heavier per-iteration work

        // Second block using updated dataptr
        if (ctr > 0) {
            tmp0 = dataptr[0] + dataptr[8];
            tmp1 = dataptr[16] + dataptr[24];
            tmp2 = dataptr[32] + dataptr[40];
            tmp3 = dataptr[48] + dataptr[56];

            tmp4 = dataptr[0] - dataptr[8];
            tmp5 = dataptr[16] - dataptr[24];
            tmp6 = dataptr[32] - dataptr[40];
            tmp7 = dataptr[48] - dataptr[56];

            tmp10 = tmp0 + tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            tmp13 = tmp0 - tmp3;

            dataptr[0] = ((tmp10 + tmp11 + 2) >> 2);
            dataptr[32] = ((tmp10 - tmp11 + 2) >> 2);
            z1 = (tmp12 + tmp13) * 4433;
            dataptr[16] = (z1 + tmp13 * 6270 + (1 << 14)) >> 15;
            dataptr[48] = (z1 + tmp12 * (-15137) + (1 << 14)) >> 15;

            tmp10 = tmp4 + tmp7;
            tmp11 = tmp5 + tmp6;
            tmp12 = tmp5 - tmp6;
            tmp13 = tmp4 - tmp7;

            dataptr[8] = ((tmp10 + tmp11 + 2) >> 2);
            dataptr[40] = ((tmp10 - tmp11 + 2) >> 2);
            z1 = (tmp12 + tmp13) * 4433;
            dataptr[24] = (z1 + tmp13 * 6270 + (1 << 14)) >> 15;
            dataptr[56] = (z1 + tmp12 * (-15137) + (1 << 14)) >> 15;

            dataptr += 2;
        }
    }
}
