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
extern INT32 tmp6;
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp17;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 16 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 7];
    tmp1 = dataptr[8 * 1] + wsptr[8 * 6];
    tmp2 = dataptr[8 * 2] + wsptr[8 * 5];
    tmp3 = dataptr[8 * 3] + wsptr[8 * 4];
    tmp4 = dataptr[8 * 4] + wsptr[8 * 3];
    tmp5 = dataptr[8 * 5] + wsptr[8 * 2];
    tmp6 = dataptr[8 * 6] + wsptr[8 * 1];
    tmp7 = dataptr[8 * 7] + wsptr[8 * 0];
    tmp10 = tmp0 + tmp7;
    tmp14 = tmp0 - tmp7;
    tmp11 = tmp1 + tmp6;
    tmp15 = tmp1 - tmp6;
    tmp12 = tmp2 + tmp5;
    tmp16 = tmp2 - tmp5;
    tmp13 = tmp3 + tmp4;
    tmp17 = tmp3 - tmp4;
    tmp0 = dataptr[8 * 0] - wsptr[8 * 7];
    tmp1 = dataptr[8 * 1] - wsptr[8 * 6];
    tmp2 = dataptr[8 * 2] - wsptr[8 * 5];
    tmp3 = dataptr[8 * 3] - wsptr[8 * 4];
    tmp4 = dataptr[8 * 4] - wsptr[8 * 3];
    tmp5 = dataptr[8 * 5] - wsptr[8 * 2];
    tmp6 = dataptr[8 * 6] - wsptr[8 * 1];
    tmp7 = dataptr[8 * 7] - wsptr[8 * 0];

    // Reduced precision and simplified scaling
    INT32 scale_shift = 3;
    dataptr[8 * 0] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 + (1 << (scale_shift - 1))) >> scale_shift);
    dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp13) * 11314 + (tmp11 - tmp12) * 4433 + (1 << (14))) >> 15));
    tmp10 = ((tmp17 - tmp15) * 2260 + (tmp14 - tmp16) * 11380);
    dataptr[8 * 2] = (DCTELEM)(((tmp10 + tmp15 * 11900 + tmp16 * 17780 + (1 << 14)) >> 15));
    dataptr[8 * 6] = (DCTELEM)(((tmp10 - tmp14 * 1730 - tmp17 * 8700 + (1 << 14)) >> 15));

    // Simplified butterfly computations with fewer multiplies
    tmp11 = (tmp0 + tmp1) * 11080;
    tmp12 = (tmp0 + tmp2) * 10210;
    tmp13 = (tmp0 + tmp3) * 8950;
    tmp14 = (tmp1 + tmp2) * 1130;
    tmp15 = (tmp1 + tmp3) * (-5460);
    tmp16 = (tmp2 + tmp3) * (-11080);

    tmp10 = tmp11 + tmp12 + tmp13 - tmp0 * 18700 + tmp7 * 6380;
    tmp11 = tmp11 + tmp14 + tmp15 + tmp1 * 590 - tmp6 * 13600;
    tmp12 = tmp12 + tmp14 + tmp16 - tmp2 * 9220 + tmp5 * 10040;
    tmp13 = tmp13 + tmp15 + tmp16 + tmp3 * 8720 + tmp4 * 17730;

    dataptr[8 * 1] = (DCTELEM)((tmp10 + (1 << 14)) >> 15);
    dataptr[8 * 3] = (DCTELEM)((tmp11 + (1 << 14)) >> 15);
    dataptr[8 * 5] = (DCTELEM)((tmp12 + (1 << 14)) >> 15);
    dataptr[8 * 7] = (DCTELEM)((tmp13 + (1 << 14)) >> 15);

    dataptr++;
    wsptr++;
}
}
