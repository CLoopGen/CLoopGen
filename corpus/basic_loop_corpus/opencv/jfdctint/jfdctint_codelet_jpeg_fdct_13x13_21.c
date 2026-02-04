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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 z1;
extern INT32 z2;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 4];
    tmp1 = dataptr[8 * 1] + wsptr[8 * 3];
    tmp2 = dataptr[8 * 2] + wsptr[8 * 2];
    tmp3 = dataptr[8 * 3] + wsptr[8 * 1];
    tmp4 = dataptr[8 * 4] + wsptr[8 * 0];
    tmp5 = dataptr[8 * 5] + dataptr[8 * 7];
    tmp6 = dataptr[8 * 6];
    tmp10 = dataptr[8 * 0] - wsptr[8 * 4];
    tmp11 = dataptr[8 * 1] - wsptr[8 * 3];
    tmp12 = dataptr[8 * 2] - wsptr[8 * 2];
    tmp13 = dataptr[8 * 3] - wsptr[8 * 1];
    tmp14 = dataptr[8 * 4] - wsptr[8 * 0];
    tmp15 = dataptr[8 * 5] - dataptr[8 * 7];
    dataptr[8 * 0] = (DCTELEM)(((((tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6) * (((INT32)((0.75739645) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    tmp6 += tmp6;
    tmp0 -= tmp6;
    tmp1 -= tmp6;
    tmp2 -= tmp6;
    tmp3 -= tmp6;
    tmp4 -= tmp6;
    tmp5 -= tmp6;
    dataptr[8 * 2] = (DCTELEM)(((((tmp0) * (((INT32)((1.039995521) * (((INT32)1) << 13) + 0.5)))) + ((tmp1) * (((INT32)((0.80174508099999997) * (((INT32)1) << 13) + 0.5)))) + ((tmp2) * (((INT32)((0.37982450400000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp3) * (((INT32)((0.12910928899999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp4) * (((INT32)((0.6084657) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((0.94842995200000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    z1 = ((tmp0 - tmp2) * (((INT32)((0.87508751600000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp3 - tmp4) * (((INT32)((0.330085509) * (((INT32)1) << 13) + 0.5)))) - ((tmp1 - tmp5) * (((INT32)((0.23967820500000001) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp0 + tmp2) * (((INT32)((0.073342434999999997) * (((INT32)1) << 13) + 0.5)))) - ((tmp3 + tmp4) * (((INT32)((0.70991001300000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp1 + tmp5) * (((INT32)((0.36878749399999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 4] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    dataptr[8 * 6] = (DCTELEM)(((z1 - z2) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    tmp1 = ((tmp10 + tmp11) * (((INT32)((1.0015149080000001) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((tmp10 + tmp12) * (((INT32)((0.88151475099999999) * (((INT32)1) << 13) + 0.5))));
    tmp3 = ((tmp10 + tmp13) * (((INT32)((0.71028416100000002) * (((INT32)1) << 13) + 0.5)))) + ((tmp14 + tmp15) * (((INT32)((0.25633587400000002) * (((INT32)1) << 13) + 0.5))));
    tmp0 = tmp1 + tmp2 + tmp3 - ((tmp10) * (((INT32)((1.5300031620000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp14) * (((INT32)((0.24143856399999999) * (((INT32)1) << 13) + 0.5))));
    tmp4 = ((tmp14 - tmp15) * (((INT32)((0.71028416100000002) * (((INT32)1) << 13) + 0.5)))) - ((tmp11 + tmp12) * (((INT32)((0.25633587400000002) * (((INT32)1) << 13) + 0.5))));
    tmp5 = ((tmp11 + tmp13) * (-((INT32)((0.88151475099999999) * (((INT32)1) << 13) + 0.5))));
    tmp1 += tmp4 + tmp5 + ((tmp11) * (((INT32)((0.63411015500000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp14) * (((INT32)((1.7735948189999999) * (((INT32)1) << 13) + 0.5))));
    tmp6 = ((tmp12 + tmp13) * (-((INT32)((0.49777443799999999) * (((INT32)1) << 13) + 0.5))));
    tmp2 += tmp4 + tmp6 - ((tmp12) * (((INT32)((1.1907150980000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp15) * (((INT32)((1.711799069) * (((INT32)1) << 13) + 0.5))));
    tmp3 += tmp5 + tmp6 + ((tmp13) * (((INT32)((1.670519935) * (((INT32)1) << 13) + 0.5)))) - ((tmp15) * (((INT32)((1.3196465319999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    dataptr[8 * 3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    dataptr[8 * 5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    dataptr[8 * 7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13 + 1) - 1))) >> (13 + 1));
    dataptr++;
    wsptr++;
}

}
