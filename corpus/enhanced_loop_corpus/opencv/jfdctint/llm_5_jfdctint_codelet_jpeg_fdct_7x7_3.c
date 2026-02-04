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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 7; ctr++) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 6];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 5];
    tmp2 = dataptr[8 * 2] + dataptr[8 * 4];
    tmp3 = dataptr[8 * 3];

    // Introduce conditional skip of certain computations based on loop index
    if (ctr != 3) {
        tmp10 = dataptr[8 * 0] - dataptr[8 * 6];
        tmp11 = dataptr[8 * 1] - dataptr[8 * 5];
        tmp12 = dataptr[8 * 2] - dataptr[8 * 4];
    } else {
        // Alternate computation path for middle iteration
        tmp10 = (dataptr[8 * 0] + dataptr[8 * 6]) >> 1;
        tmp11 = (dataptr[8 * 1] + dataptr[8 * 5]) >> 1;
        tmp12 = (dataptr[8 * 2] + dataptr[8 * 4]) >> 1;
    }

    z1 = tmp0 + tmp2;
    dataptr[8 * 0] = (DCTELEM)(((((z1 + tmp1 + tmp3) * (((INT32)((1.3061224490000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp3 += tmp3;
    z1 -= tmp3;
    z1 -= tmp3;
    z1 = ((z1) * (((INT32)((0.46178402000000002) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp2) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5))));
    z3 = ((tmp1 - tmp2) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 2] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    z1 -= z2;
    z2 = ((tmp0 - tmp1) * (((INT32)((1.1516705089999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 4] = (DCTELEM)(((z2 + z3 - ((tmp1 - tmp3) * (((INT32)((0.92356804100000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 6] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    // Conditional early partial assignment
    if (ctr < 5) {
        tmp1 = ((tmp10 + tmp11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp10 - tmp11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;
        tmp2 = ((tmp11 + tmp12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));
        tmp1 += tmp2;
        tmp3 = ((tmp10 + tmp12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));
        tmp0 += tmp3;
        tmp2 += tmp3 + ((tmp12) * (((INT32)((2.4435313550000002) * (((INT32)1) << 13) + 0.5))));
    } else {
        // Fallback symmetric pattern with sign flip to maintain diversity
        tmp1 = ((tmp11 + tmp10) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp11 - tmp10) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp2 - tmp1;
        tmp1 += tmp2;
        tmp2 = ((tmp12 + tmp11) * (((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));
        tmp1 -= tmp2;
        tmp3 = ((tmp12 + tmp10) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));
        tmp0 -= tmp3;
        tmp2 -= tmp3 + ((tmp12) * (((INT32)((-2.4435313550000002) * (((INT32)1) << 13) + 0.5))));
    }

    dataptr[8 * 1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr++;
}
}
