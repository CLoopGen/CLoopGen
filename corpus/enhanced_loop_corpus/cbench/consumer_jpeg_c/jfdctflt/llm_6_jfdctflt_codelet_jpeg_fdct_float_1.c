#include <stdio.h>

#include <inttypes.h>

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



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    float t0 = dataptr[8 * 0] + dataptr[8 * 7];
    float t7 = dataptr[8 * 0] - dataptr[8 * 7];
    float t1 = dataptr[8 * 1] + dataptr[8 * 6];
    float t6 = dataptr[8 * 1] - dataptr[8 * 6];
    float t2 = dataptr[8 * 2] + dataptr[8 * 5];
    float t5 = dataptr[8 * 2] - dataptr[8 * 5];
    float t3 = dataptr[8 * 3] + dataptr[8 * 4];
    float t4 = dataptr[8 * 3] - dataptr[8 * 4];

    float u10 = t0 + t3;
    float u13 = t0 - t3;
    float u11 = t1 + t2;
    float u12 = t1 - t2;

    // Eliminate WAW dependency by using temporaries until all reads are done
    float out0 = u10 + u11;
    float out4 = u10 - u11;
    float z1_val = (u12 + u13) * ((float)0.70710678100000002);
    float out2 = u13 + z1_val;
    float out6 = u13 - z1_val;

    float v10 = t4 + t5;
    float v11 = t5 + t6;
    float v12 = t6 + t7;
    float z5_val = (v10 - v12) * ((float)0.38268343300000002);
    float z2_val = ((float)0.54119609999999996) * v10 + z5_val;
    float z4_val = ((float)1.3065629649999999) * v12 + z5_val;
    float z3_val = v11 * ((float)0.70710678100000002);
    float z11_val = t7 + z3_val;
    float z13_val = t7 - z3_val;

    float out5 = z13_val + z2_val;
    float out3 = z13_val - z2_val;
    float out1 = z11_val + z4_val;
    float out7 = z11_val - z4_val;

    // Final write-back with no overlapping read-after-write hazards
    dataptr[8 * 0] = out0;
    dataptr[8 * 4] = out4;
    dataptr[8 * 2] = out2;
    dataptr[8 * 6] = out6;
    dataptr[8 * 5] = out5;
    dataptr[8 * 3] = out3;
    dataptr[8 * 1] = out1;
    dataptr[8 * 7] = out7;

    dataptr++;
}
}
