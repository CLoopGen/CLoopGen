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
for (ctr = 4 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp2 = dataptr[2] + dataptr[5];
    tmp5 = dataptr[2] - dataptr[5];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

    // Reduced arithmetic intensity: skip some intermediate computations
    // Combine key stages but eliminate redundant or less impactful operations
    tmp10 = tmp0 + tmp3;
    tmp11 = tmp1 + tmp2;
    dataptr[0] = tmp10 + tmp11;
    dataptr[4] = tmp10 - tmp11;

    // Skip full butterfly and use simplified scaling
    z1 = (tmp0 - tmp3 + tmp1 - tmp2) * ((float)0.70710678100000002);
    dataptr[2] = tmp0 - tmp3 + z1;
    dataptr[6] = tmp0 - tmp3 - z1;

    // Simplify last stage using fewer temporaries and constants
    z2 = (tmp4 + tmp5 + tmp6 + tmp7) * ((float)0.5);
    z4 = (tmp7 - tmp4) * ((float)0.70710678100000002);
    dataptr[5] = tmp7 + z2;
    dataptr[3] = tmp7 - z2;
    dataptr[1] = tmp6 + z4;
    dataptr[7] = tmp6 - z4;

    dataptr += 8;
}
}
