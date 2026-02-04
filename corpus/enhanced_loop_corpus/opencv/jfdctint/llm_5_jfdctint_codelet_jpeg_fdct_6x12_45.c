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

    if (ctr % 2 == 0) {
        tmp10 = tmp0 + tmp5;
        tmp13 = tmp0 - tmp5;
        tmp11 = tmp1 + tmp4;
        tmp14 = tmp1 - tmp4;
        tmp12 = tmp2 + tmp3;
        tmp15 = tmp2 - tmp3;
    } else {
        tmp10 = tmp0 - tmp4;
        tmp13 = tmp1 + tmp5;
        tmp11 = tmp2 - tmp3;
        tmp14 = tmp0 + tmp1;
        tmp12 = tmp3 + tmp4;
        tmp15 = tmp2 + tmp5;
    }

    tmp0 = dataptr[8 * 0] - wsptr[8 * 3];
    tmp1 = dataptr[8 * 1] - wsptr[8 * 2];
    tmp2 = dataptr[8 * 2] - wsptr[8 * 1];
    tmp3 = dataptr[8 * 3] - wsptr[8 * 0];
    tmp4 = dataptr[8 * 4] - dataptr[8 * 7];
    tmp5 = dataptr[8 * 5] - dataptr[8 * 6];

    if (ctr < 3) {
        dataptr[8 * 0] = (DCTELEM)(((((tmp10 + tmp11 + tmp12) * (((INT32)((0.88888888899999995) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[8 * 6] = (DCTELEM)(((((tmp13 - tmp14 - tmp15) * (((INT32)((0.88888888899999995) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    } else {
        INT32 scaled_factor = (INT32)((0.707) * ((INT32)1 << 13) + 0.5);
        dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp12) * scaled_factor) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[8 * 6] = (DCTELEM)((((tmp13 + tmp15) * scaled_factor) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    }

    dataptr[8 * 4] = (DCTELEM)(((((tmp10 - tmp12) * (((INT32)((1.0886621080000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    if (ctr == 0 || ctr == 5) {
        dataptr[8 * 2] = (DCTELEM)(((((tmp14 - tmp15) * (((INT32)((0.88888888899999995) * (((INT32)1) << 13) + 0.5)))) + ((tmp13 + tmp15) * (((INT32)((1.2142448029999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    } else {
        dataptr[8 * 2] = (DCTELEM)(((((tmp10 - tmp11) * (((INT32)((0.99730760299999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    }

    tmp10 = ((tmp1 + tmp4) * (((INT32)((0.48106320000000002) * (((INT32)1) << 13) + 0.5))));
    tmp14 = tmp10 + ((tmp1) * (((INT32)((0.68032610199999999) * (((INT32)1) << 13) + 0.5))));
    tmp15 = tmp10 - ((tmp4) * (((INT32)((1.642452502) * (((INT32)1) << 13) + 0.5))));
    tmp12 = ((tmp0 + tmp2) * (((INT32)((0.99730760299999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = ((tmp0 + tmp3) * (((INT32)((0.76526103899999998) * (((INT32)1) << 13) + 0.5))));

    if (ctr != 2 && ctr != 4) {
        tmp10 = tmp12 + tmp13 + tmp14 - ((tmp0) * (((INT32)((0.51624440299999996) * (((INT32)1) << 13) + 0.5)))) + ((tmp5) * (((INT32)((0.164081699) * (((INT32)1) << 13) + 0.5))));
    } else {
        tmp10 = tmp12 - tmp14 + ((tmp5) * (((INT32)((0.5) * (((INT32)1) << 13) + 0.5))));
    }

    tmp11 = ((tmp2 + tmp3) * (-((INT32)((0.164081699) * (((INT32)1) << 13) + 0.5))));
    tmp12 += tmp11 - tmp15 - ((tmp2) * (((INT32)((2.0795501440000002) * (((INT32)1) << 13) + 0.5)))) + ((tmp5) * (((INT32)((0.76526103899999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 += tmp11 - tmp14 + ((tmp3) * (((INT32)((0.64514489900000005) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((0.99730760299999998) * (((INT32)1) << 13) + 0.5))));
    tmp11 = tmp15 + ((tmp0 - tmp3) * (((INT32)((1.1613893019999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp2 + tmp5) * (((INT32)((0.48106320000000002) * (((INT32)1) << 13) + 0.5))));

    dataptr[8 * 1] = (DCTELEM)(((tmp10) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)(((tmp11) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 5] = (DCTELEM)(((tmp12) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 7] = (DCTELEM)(((tmp13) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr++;
    wsptr++;
}
}
