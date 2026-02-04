#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp0;
extern float tmp1;
extern float tmp2;
extern float tmp3;
extern float tmp4;
extern float tmp5;
extern float tmp6;
extern float tmp7;
extern float tmp10;
extern float tmp11;
extern float tmp12;
extern float tmp13;
extern float z1;
extern float z2;
extern float z3;
extern float z4;
extern float z5;
extern float z11;
extern float z13;
extern float *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 16 - 1; ctr >= 0; ctr--) {
        if (ctr < 8) {
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

            dataptr[0] = tmp10 + tmp11;
            dataptr[4] = tmp10 - tmp11;

            z1 = (tmp12 + tmp13) * 0.707106781f;
            dataptr[2] = tmp13 + z1;
            dataptr[6] = tmp13 - z1;

            tmp10 = tmp4 + tmp5;
            tmp11 = tmp5 + tmp6;
            tmp12 = tmp6 + tmp7;
            z5 = (tmp10 - tmp12) * 0.382683433f;
            z2 = 0.5411961f * tmp10 + z5;
            z4 = 1.306562965f * tmp12 + z5;
            z3 = tmp11 * 0.707106781f;
            z11 = tmp7 + z3;
            z13 = tmp7 - z3;

            dataptr[5] = z13 + z2;
            dataptr[3] = z13 - z2;
            dataptr[1] = z11 + z4;
            dataptr[7] = z11 - z4;

            dataptr += 8;
        } else {
            tmp0 = dataptr[0];
            tmp1 = dataptr[1];
            tmp2 = dataptr[2];
            tmp3 = dataptr[3];

            dataptr[0] = tmp0 + tmp1;
            dataptr[1] = tmp1 - tmp0;
            dataptr[2] = tmp2 + tmp3;
            dataptr[3] = tmp3 - tmp2;

            dataptr += 4;
        }
    }
}
