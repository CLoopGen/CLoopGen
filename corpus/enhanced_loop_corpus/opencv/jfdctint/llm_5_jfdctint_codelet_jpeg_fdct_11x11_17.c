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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Introduce loop-carried dependency via accumulation in tmp_acc across iterations
    static INT32 tmp_acc = 0;  // Creates loop-carried dependency (RAW)
    tmp_acc += dataptr[8 * 0];  // Use previous iteration's value

    tmp0 = dataptr[8 * 0] + wsptr[8 * 2] + (ctr & tmp_acc);  // Artificially inject dependency
    tmp1 = dataptr[8 * 1] + wsptr[8 * 1];
    tmp2 = dataptr[8 * 2] + wsptr[8 * 0];
    tmp3 = dataptr[8 * 3] + dataptr[8 * 7];
    tmp4 = dataptr[8 * 4] + dataptr[8 * 6];
    tmp5 = dataptr[8 * 5];
    tmp10 = dataptr[8 * 0] - wsptr[8 * 2];
    tmp11 = dataptr[8 * 1] - wsptr[8 * 1];
    tmp12 = dataptr[8 * 2] - wsptr[8 * 0];
    tmp13 = dataptr[8 * 3] - dataptr[8 * 7];
    tmp14 = dataptr[8 * 4] - dataptr[8 * 6];

    // Delayed write: make sure writes to dataptr occur only at end to enforce WAW
    INT32 out0, out2, out4, out6, out1, out3, out5, out7;

    tmp5 += tmp5;
    tmp0 -= tmp5;
    tmp1 -= tmp5;
    tmp2 -= tmp5;
    tmp3 -= tmp5;
    tmp4 -= tmp5;

    z1 = ((tmp0 + tmp3) * (((INT32)((1.435427942) * (((INT32)1) << 13) + 0.5)))) + ((tmp2 + tmp4) * (((INT32)((0.212906922) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp1 - tmp3) * (((INT32)((0.97968971299999996) * (((INT32)1) << 13) + 0.5))));
    z3 = ((tmp0 - tmp1) * (((INT32)((1.258538479) * (((INT32)1) << 13) + 0.5))));

    out0 = ((((tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp_acc) * (((INT32)((1.05785124) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    out2 = (((z1 + z2 - ((tmp3) * (((INT32)((1.077210542) * (((INT32)1) << 13) + 0.5)))) - ((tmp4) * (((INT32)((1.4714453999999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    out4 = (((z2 + z3 + ((tmp1) * (((INT32)((0.065941843999999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp2) * (((INT32)((1.435427942) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((0.62147231199999997) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    out6 = (((z1 + z3 - ((tmp0) * (((INT32)((1.7142767080000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp2) * (((INT32)((0.83437923400000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    tmp1 = ((tmp10 + tmp11) * (((INT32)((1.360834544) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((tmp10 + tmp12) * (((INT32)((1.130622199) * (((INT32)1) << 13) + 0.5))));
    tmp3 = ((tmp10 + tmp13) * (((INT32)((0.80881356800000004) * (((INT32)1) << 13) + 0.5))));
    out0 += tmp1 + tmp2 + tmp3 - ((tmp10) * (((INT32)((1.8194701449999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp14) * (((INT32)((0.42147967200000003) * (((INT32)1) << 13) + 0.5))));  // reuse out0 as accumulator

    tmp4 = ((tmp11 + tmp12) * (-((INT32)((0.80881356800000004) * (((INT32)1) << 13) + 0.5))));
    tmp5 = ((tmp11 + tmp13) * (-((INT32)((1.4808001669999999) * (((INT32)1) << 13) + 0.5))));
    out1 = tmp1 + tmp4 + tmp5 + ((tmp11) * (((INT32)((1.3502588639999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((1.130622199) * (((INT32)1) << 13) + 0.5))));
    tmp10 = ((tmp12 + tmp13) * (((INT32)((0.42147967200000003) * (((INT32)1) << 13) + 0.5))));
    out3 = tmp2 + tmp4 + tmp10 - ((tmp12) * (((INT32)((2.1041228470000002) * (((INT32)1) << 13) + 0.5)))) + ((tmp14) * (((INT32)((1.4808001669999999) * (((INT32)1) << 13) + 0.5))));
    out5 = tmp3 + tmp5 + tmp10 + ((tmp13) * (((INT32)((1.381129125) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((1.360834544) * (((INT32)1) << 13) + 0.5))));

    // All writes happen at the end to enforce strict WAW order
    dataptr[8 * 0] = (DCTELEM)(out0);
    dataptr[8 * 2] = (DCTELEM)(out2);
    dataptr[8 * 4] = (DCTELEM)(out4);
    dataptr[8 * 6] = (DCTELEM)(out6);
    dataptr[8 * 1] = (DCTELEM)(out1);
    dataptr[8 * 3] = (DCTELEM)(out3);
    dataptr[8 * 5] = (DCTELEM)(out5);
    dataptr[8 * 7] = (DCTELEM)(out5 + out7);  // artificial dependency

    dataptr++;
    wsptr++;
    tmp_acc &= 0xFFFF;  // bound accumulator
}
}
