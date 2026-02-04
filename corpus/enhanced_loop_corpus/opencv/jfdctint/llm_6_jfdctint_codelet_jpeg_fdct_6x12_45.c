#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 6; ctr++) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 3];
    tmp1 = dataptr[8 * 1] + wsptr[8 * 2];
    tmp2 = dataptr[8 * 2] + wsptr[8 * 1];
    tmp3 = dataptr[8 * 3] + wsptr[8 * 0];
    tmp4 = dataptr[8 * 4] + dataptr[8 * 7];
    tmp5 = dataptr[8 * 5] + dataptr[8 * 6];
    tmp10 = tmp0 + tmp5;
    tmp13 = tmp0 - tmp5;
    tmp11 = tmp1 + tmp4;
    tmp14 = tmp1 - tmp4;
    tmp12 = tmp2 + tmp3;
    tmp15 = tmp2 - tmp3;

    // Introduce temporary variables to break WAW and WAR hazards
    INT32 t0, t1, t2, t3, t4, t5;
    t0 = dataptr[8 * 0] - wsptr[8 * 3];
    t1 = dataptr[8 * 1] - wsptr[8 * 2];
    t2 = dataptr[8 * 2] - wsptr[8 * 1];
    t3 = dataptr[8 * 3] - wsptr[8 * 0];
    t4 = dataptr[8 * 4] - dataptr[8 * 7];
    t5 = dataptr[8 * 5] - dataptr[8 * 6];

    // Reorder independent computations to reduce loop-carried dependencies
    INT32 coef1 = ((INT32)((0.88888888899999995) * (((INT32)1) << 13) + 0.5));
    INT32 coef2 = ((INT32)((1.0886621080000001) * (((INT32)1) << 13) + 0.5));
    INT32 coef3 = ((INT32)((1.2142448029999999) * (((INT32)1) << 13) + 0.5));
    INT32 coef4 = ((INT32)((0.48106320000000002) * (((INT32)1) << 13) + 0.5));
    INT32 coef5 = ((INT32)((0.68032610199999999) * (((INT32)1) << 13) + 0.5));
    INT32 coef6 = ((INT32)((1.642452502) * (((INT32)1) << 13) + 0.5));
    INT32 coef7 = ((INT32)((0.99730760299999998) * (((INT32)1) << 13) + 0.5));
    INT32 coef8 = ((INT32)((0.76526103899999998) * (((INT32)1) << 13) + 0.5));
    INT32 coef9 = ((INT32)((0.51624440299999996) * (((INT32)1) << 13) + 0.5));
    INT32 coef10 = ((INT32)((0.164081699) * (((INT32)1) << 13) + 0.5));
    INT32 coef11 = -((INT32)((0.164081699) * (((INT32)1) << 13) + 0.5));
    INT32 coef12 = ((INT32)((2.0795501440000002) * (((INT32)1) << 13) + 0.5));
    INT32 coef13 = ((INT32)((0.64514489900000005) * (((INT32)1) << 13) + 0.5));
    INT32 coef14 = ((INT32)((1.1613893019999999) * (((INT32)1) << 13) + 0.5));

    INT32 shift = (13 + 2);
    INT32 round = ((INT32)1 << (shift - 1));

    dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11 + tmp12) * coef1) + round) >> shift);
    dataptr[8 * 6] = (DCTELEM)((((tmp13 - tmp14 - tmp15) * coef1) + round) >> shift);
    dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp12) * coef2) + round) >> shift);
    dataptr[8 * 2] = (DCTELEM)((((tmp14 - tmp15) * coef1 + (tmp13 + tmp15) * coef3) + round) >> shift);

    INT32 partA = (t1 + t4) * coef4;
    INT32 partB = partA + t1 * coef5;
    INT32 partC = partA - t4 * coef6;
    INT32 partD = (t0 + t2) * coef7;
    INT32 partE = (t0 + t3) * coef8;

    tmp10 = partD + partE + partB - t0 * coef9 + t5 * coef10;
    tmp11 = (t2 + t3) * coef11;
    tmp12 = partD + tmp11 - partC - t2 * coef12 + t5 * coef8;
    tmp13 = partE + tmp11 - partB + t3 * coef13 - t5 * coef7;
    tmp11 = partC + (t0 - t3) * coef14 - (t2 + t5) * coef4;

    dataptr[8 * 1] = (DCTELEM)(((tmp10) + round) >> shift);
    dataptr[8 * 3] = (DCTELEM)(((tmp11) + round) >> shift);
    dataptr[8 * 5] = (DCTELEM)(((tmp12) + round) >> shift);
    dataptr[8 * 7] = (DCTELEM)(((tmp13) + round) >> shift);

    dataptr++;
    wsptr++;
}
}
