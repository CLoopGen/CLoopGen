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
for (ctr = 16 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 2];
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

    INT32 sum_all = tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5;
    INT32 scaled_sum = (sum_all * ((INT32)((1.05785124) * (((INT32)1) << 13) + 0.5)));
    dataptr[8 * 0] = (DCTELEM)((scaled_sum + ((INT32)1 << (14))) >> 15);

    tmp5 <<= 1;
    tmp0 -= tmp5;
    tmp1 -= tmp5;
    tmp2 -= tmp5;
    tmp3 -= tmp5;
    tmp4 -= tmp5;

    INT32 c13 = (INT32)((1.435427942) * (((INT32)1) << 13) + 0.5);
    INT32 c21 = (INT32)((0.212906922) * (((INT32)1) << 13) + 0.5);
    INT32 c097 = (INT32)((0.97968971299999996) * (((INT32)1) << 13) + 0.5);
    INT32 c125 = (INT32)((1.258538479) * (((INT32)1) << 13) + 0.5);
    INT32 c107 = (INT32)((1.077210542) * (((INT32)1) << 13) + 0.5);
    INT32 c147 = (INT32)((1.4714453999999999) * (((INT32)1) << 13) + 0.5);
    INT32 c006 = (INT32)((0.065941843999999999) * (((INT32)1) << 13) + 0.5);
    INT32 c062 = (INT32)((0.62147231199999997) * (((INT32)1) << 13) + 0.5);
    INT32 c171 = (INT32)((1.7142767080000001) * (((INT32)1) << 13) + 0.5);
    INT32 c083 = (INT32)((0.83437923400000002) * (((INT32)1) << 13) + 0.5);

    z1 = ((tmp0 + tmp3) * c13) + ((tmp2 + tmp4) * c21);
    z2 = (tmp1 - tmp3) * c097;
    z3 = (tmp0 - tmp1) * c125;

    dataptr[8 * 2] = (DCTELEM)(((z1 + z2 - tmp3 * c107 - tmp4 * c147) + (1 << 14)) >> 15);
    dataptr[8 * 4] = (DCTELEM)(((z2 + z3 + tmp1 * c006 - tmp2 * c13 + tmp4 * c062) + (1 << 14)) >> 15);
    dataptr[8 * 6] = (DCTELEM)(((z1 + z3 - tmp0 * c171 - tmp2 * c083) + (1 << 14)) >> 15);

    INT32 d136 = (INT32)((1.360834544) * (((INT32)1) << 13) + 0.5);
    INT32 d113 = (INT32)((1.130622199) * (((INT32)1) << 13) + 0.5);
    INT32 d080 = (INT32)((0.80881356800000004) * (((INT32)1) << 13) + 0.5);
    INT32 d181 = (INT32)((1.8194701449999999) * (((INT32)1) << 13) + 0.5);
    INT32 d042 = (INT32)((0.42147967200000003) * (((INT32)1) << 13) + 0.5);
    INT32 d148 = (INT32)((1.4808001669999999) * (((INT32)1) << 13) + 0.5);
    INT32 d135 = (INT32)((1.3502588639999999) * (((INT32)1) << 13) + 0.5);
    INT32 d210 = (INT32)((2.1041228470000002) * (((INT32)1) << 13) + 0.5);
    INT32 d138 = (INT32)((1.381129125) * (((INT32)1) << 13) + 0.5);

    tmp1 = (tmp10 + tmp11) * d136;
    tmp2 = (tmp10 + tmp12) * d113;
    tmp3 = (tmp10 + tmp13) * d080;
    tmp0 = tmp1 + tmp2 + tmp3 - tmp10 * d181 + tmp14 * d042;

    tmp4 = (tmp11 + tmp12) * (-d080);
    tmp5 = (tmp11 + tmp13) * (-d148);
    tmp1 += tmp4 + tmp5 + tmp11 * d135 - tmp14 * d113;

    tmp10 = (tmp12 + tmp13) * d042;
    tmp2 += tmp4 + tmp10 - tmp12 * d210 + tmp14 * d148;
    tmp3 += tmp5 + tmp10 + tmp13 * d138 - tmp14 * d136;

    dataptr[8 * 1] = (DCTELEM)((tmp0 + (1 << 14)) >> 15);
    dataptr[8 * 3] = (DCTELEM)((tmp1 + (1 << 14)) >> 15);
    dataptr[8 * 5] = (DCTELEM)((tmp2 + (1 << 14)) >> 15);
    dataptr[8 * 7] = (DCTELEM)((tmp3 + (1 << 14)) >> 15);

    dataptr++;
    wsptr++;
}
}
