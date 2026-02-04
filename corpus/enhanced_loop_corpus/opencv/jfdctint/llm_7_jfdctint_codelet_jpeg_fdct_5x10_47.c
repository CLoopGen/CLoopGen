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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ctr++) {
    INT32 d0 = dataptr[8 * 0], d1 = dataptr[8 * 1], d2 = dataptr[8 * 2], d3 = dataptr[8 * 3];
    INT32 d4 = dataptr[8 * 4], d5 = dataptr[8 * 5], d6 = dataptr[8 * 6], d7 = dataptr[8 * 7];
    INT32 w1 = wsptr[8 * 1], w0 = wsptr[8 * 0];

    tmp0 = d0 + w1;
    tmp1 = d1 + w0;
    tmp12 = d2 + d7;
    tmp3 = d3 + d6;
    tmp4 = d4 + d5;

    tmp10 = tmp0 + tmp4;
    tmp13 = tmp0 - tmp4;
    tmp11 = tmp1 + tmp3;
    tmp14 = tmp1 - tmp3;

    tmp0 = d0 - w1;
    tmp1 = d1 - w0;
    tmp2 = d2 - d7;
    tmp3 = d3 - d6;
    tmp4 = d4 - d5;

    INT32 c128 = ((INT32)((1.28) * (((INT32)1) << 13) + 0.5));
    INT32 c146 = ((INT32)((1.4644771910000001) * (((INT32)1) << 13) + 0.5));
    INT32 c055 = ((INT32)((0.55938051099999997) * (((INT32)1) << 13) + 0.5));
    INT32 c106 = ((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5));
    INT32 c065 = ((INT32)((0.65759122999999997) * (((INT32)1) << 13) + 0.5));
    INT32 c278 = ((INT32)((2.7856011509999998) * (((INT32)1) << 13) + 0.5));
    INT32 c178 = ((INT32)((1.7879068760000001) * (((INT32)1) << 13) + 0.5));
    INT32 c161 = ((INT32)((1.6128940940000001) * (((INT32)1) << 13) + 0.5));
    INT32 c082 = ((INT32)((0.82181058799999995) * (((INT32)1) << 13) + 0.5));
    INT32 c028 = ((INT32)((0.28317662999999998) * (((INT32)1) << 13) + 0.5));
    INT32 c121 = ((INT32)((1.217352341) * (((INT32)1) << 13) + 0.5));
    INT32 c075 = ((INT32)((0.75236512300000002) * (((INT32)1) << 13) + 0.5));
    INT32 c039 = ((INT32)((0.395541753) * (((INT32)1) << 13) + 0.5));
    INT32 c064 = ((INT32)((0.64000000000000001) * (((INT32)1) << 13) + 0.5));

    INT32 shift = (INT32)1 << (13 + 2 - 1);
    INT32 den = 13 + 2;

    tmp12 += tmp12;
    INT32 partA = (tmp10 + tmp11 + d2 + d7) * c128;
    dataptr[8 * 0] = (DCTELEM)((partA + shift) >> den);

    INT32 diffTerm = (tmp10 - tmp12) * c146 - (tmp11 - tmp12) * c055;
    dataptr[8 * 4] = (DCTELEM)((diffTerm + shift) >> den);

    INT32 sum13_14 = (tmp13 + tmp14) * c106;
    dataptr[8 * 2] = (DCTELEM)(((sum13_14 + (tmp13 * c065)) + shift) >> den);
    dataptr[8 * 6] = (DCTELEM)(((sum13_14 - (tmp14 * c278)) + shift) >> den);

    INT32 t10 = tmp0 + tmp4;
    INT32 t11 = tmp1 - tmp3;
    INT32 val5 = (t10 - t11 - tmp2) * c128;
    dataptr[8 * 5] = (DCTELEM)((val5 + shift) >> den);

    INT32 scaled_tmp2 = tmp2 * c128;
    INT32 sum1 = tmp0 * c178 + tmp1 * c161 + scaled_tmp2 + tmp3 * c082 + tmp4 * c028;
    dataptr[8 * 1] = (DCTELEM)((sum1 + shift) >> den);

    INT32 term12 = (tmp0 - tmp4) * c121 - (tmp1 + tmp3) * c075;
    INT32 term13 = (t10 + t11) * c039 + t11 * c064 - scaled_tmp2;
    dataptr[8 * 3] = (DCTELEM)(((term12 + term13) + shift) >> den);
    dataptr[8 * 7] = (DCTELEM)(((term12 - term13) + shift) >> den);

    dataptr++;
    wsptr++;
}
}
