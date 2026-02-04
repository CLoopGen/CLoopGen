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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
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

    INT32 sum_04 = (tmp10 + tmp11 + tmp12 + tmp13);
    dataptr[8 * 0] = (DCTELEM)((sum_04 + ((INT32)1 << ((2 + 2) - 1))) >> (2 + 2));

    INT32 diff_10_13 = tmp10 - tmp13;
    INT32 diff_11_12 = tmp11 - tmp12;
    INT32 scaled_diff_10_13 = diff_10_13 * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)));
    INT32 scaled_diff_11_12 = diff_11_12 * (((INT32)4433));
    dataptr[8 * 4] = (DCTELEM)(((scaled_diff_10_13 + scaled_diff_11_12) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    INT32 term_a = (tmp17 - tmp15) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5)));
    INT32 term_b = (tmp14 - tmp16) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5)));
    tmp10 = term_a + term_b;

    INT32 scaled_tmp15 = tmp15 * (((INT32)((1.4517749820000001) * (((INT32)1) << 13) + 0.5)));
    INT32 scaled_tmp16 = tmp16 * (((INT32)((2.1727348040000001) * (((INT32)1) << 13) + 0.5)));
    dataptr[8 * 2] = (DCTELEM)(((tmp10 + scaled_tmp15 + scaled_tmp16) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    INT32 scaled_tmp14 = tmp14 * (((INT32)((0.211164243) * (((INT32)1) << 13) + 0.5)));
    INT32 scaled_tmp17 = tmp17 * (((INT32)((1.0615943379999999) * (((INT32)1) << 13) + 0.5)));
    dataptr[8 * 6] = (DCTELEM)(((tmp10 - scaled_tmp14 - scaled_tmp17) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    INT32 base0 = tmp0, base1 = tmp1, base2 = tmp2, base3 = tmp3, base4 = tmp4, base5 = tmp5, base6 = tmp6, base7 = tmp7;

    tmp11 = ((base0 + base1) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((base6 - base7) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
    tmp12 = ((base0 + base2) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5)))) + ((base5 + base7) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
    tmp13 = ((base0 + base3) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5)))) + ((base4 - base7) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
    tmp14 = ((base1 + base2) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5)))) + ((base6 - base5) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
    tmp15 = ((base1 + base3) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5)))) + ((base4 + base6) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
    tmp16 = ((base2 + base3) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)))) + ((base5 - base4) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));

    tmp10 = tmp11 + tmp12 + tmp13 - (base0 * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5)))) + (base7 * (((INT32)((0.77965362500000002) * (((INT32)1) << 13) + 0.5))));
    tmp11 = tmp11 + tmp14 + tmp15 + (base1 * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5)))) - (base6 * (((INT32)((1.663905119) * (((INT32)1) << 13) + 0.5))));
    tmp12 = tmp12 + tmp14 + tmp16 - (base2 * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5)))) + (base5 * (((INT32)((1.227391138) * (((INT32)1) << 13) + 0.5))));
    tmp13 = tmp13 + tmp15 + tmp16 + (base3 * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5)))) + (base4 * (((INT32)((2.1679856919999998) * (((INT32)1) << 13) + 0.5))));

    dataptr[8 * 1] = (DCTELEM)(((tmp10) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 3] = (DCTELEM)(((tmp11) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 5] = (DCTELEM)(((tmp12) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));
    dataptr[8 * 7] = (DCTELEM)(((tmp13) + ((INT32)1 << ((13 + 2 + 2) - 1))) >> (13 + 2 + 2));

    dataptr++;
    wsptr++;
}
}
