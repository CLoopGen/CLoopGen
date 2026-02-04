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
    // Introduce loop-carried dependency via cumulative sum
    static INT32 cum_sum = 0;
    tmp0 = dataptr[8 * 0] + wsptr[8 * 3] + (cum_sum & 0xF);  // Add low bits of cumulative state
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

    // Delayed write using intermediate storage to create artificial RAW/WAW
    INT32 store0, store2, store4, store6;
    INT32 scale = ((INT32)((0.88888888899999995) * (((INT32)1) << 13) + 0.5));
    INT32 scale2 = ((INT32)((1.0886621080000001) * (((INT32)1) << 13) + 0.5));
    INT32 scale3 = ((INT32)((1.2142448029999999) * (((INT32)1) << 13) + 0.5));
    INT32 shift = 13 + 2;
    INT32 round = ((INT32)1 << (shift - 1));

    store0 = ((((tmp10 + tmp11 + tmp12) * scale) + round) >> shift);
    store6 = ((((tmp13 - tmp14 - tmp15) * scale) + round) >> shift);
    store4 = ((((tmp10 - tmp12) * scale2) + round) >> shift);
    store2 = ((((tmp14 - tmp15) * scale + (tmp13 + tmp15) * scale3) + round) >> shift);

    // Reuse tmp values only after all reads — enforce WAW safety
    tmp0 = dataptr[8 * 0] - wsptr[8 * 3];
    tmp1 = dataptr[8 * 1] - wsptr[8 * 2];
    tmp2 = dataptr[8 * 2] - wsptr[8 * 1];
    tmp3 = dataptr[8 * 3] - wsptr[8 * 0];
    tmp4 = dataptr[8 * 4] - dataptr[8 * 7];
    tmp5 = dataptr[8 * 5] - dataptr[8 * 6];

    // Create artificial dependency chain: tmp10 depends on prior iteration's cum_sum
    tmp10 = ((tmp1 + tmp4) * (((INT32)((0.48106320000000002) * (((INT32)1) << 13) + 0.5)))) + (cum_sum >> 16);
    tmp14 = tmp10 + ((tmp1) * (((INT32)((0.68032610199999999) * (((INT32)1) << 13) + 0.5))));
    tmp15 = tmp10 - ((tmp4) * (((INT32)((1.642452502) * (((INT32)1) << 13) + 0.5))));

    tmp12 = ((tmp0 + tmp2) * (((INT32)((0.99730760299999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = ((tmp0 + tmp3) * (((INT32)((0.76526103899999998) * (((INT32)1) << 13) + 0.5))));

    tmp10 = tmp12 + tmp13 + tmp14 - ((tmp0) * (((INT32)((0.51624440299999996) * (((INT32)1) << 13) + 0.5)))) + ((tmp5) * (((INT32)((0.164081699) * (((INT32)1) << 13) + 0.5))));
    tmp11 = ((tmp2 + tmp3) * (-((INT32)((0.164081699) * (((INT32)1) << 13) + 0.5))));
    tmp12 = tmp12 + tmp11 - tmp15 - ((tmp2) * (((INT32)((2.0795501440000002) * (((INT32)1) << 13) + 0.5)))) + ((tmp5) * (((INT32)((0.76526103899999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = tmp13 + tmp11 - tmp14 + ((tmp3) * (((INT32)((0.64514489900000005) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((0.99730760299999998) * (((INT32)1) << 13) + 0.5))));
    tmp11 = tmp15 + ((tmp0 - tmp3) * (((INT32)((1.1613893019999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp2 + tmp5) * (((INT32)((0.48106320000000002) * (((INT32)1) << 13) + 0.5))));

    // Now perform delayed writes
    dataptr[8 * 0] = (DCTELEM)(store0);
    dataptr[8 * 6] = (DCTELEM)(store6);
    dataptr[8 * 4] = (DCTELEM)(store4);
    dataptr[8 * 2] = (DCTELEM)(store2);
    dataptr[8 * 1] = (DCTELEM)(((tmp10) + round) >> shift);
    dataptr[8 * 3] = (DCTELEM)(((tmp11) + round) >> shift);
    dataptr[8 * 5] = (DCTELEM)(((tmp12) + round) >> shift);
    dataptr[8 * 7] = (DCTELEM)(((tmp13) + round) >> shift);

    // Update cumulative state for next iteration (introduce loop-carried dependency)
    cum_sum += (store0 ^ store2 ^ store4 ^ store6);

    dataptr++;
    wsptr++;
}
}
