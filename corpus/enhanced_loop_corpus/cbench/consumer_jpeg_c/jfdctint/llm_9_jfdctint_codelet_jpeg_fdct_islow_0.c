#include <stdio.h>

#include <inttypes.h>

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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp2 = dataptr[2] + dataptr[5];
    tmp5 = dataptr[2] - dataptr[5];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = (DCTELEM)((tmp10 + tmp11) << 2);
    dataptr[4] = (DCTELEM)((tmp10 - tmp11) << 2);

    z1 = (tmp12 + tmp13) * 4433LL;
    z2 = tmp13 * 6270LL;
    z3 = tmp12 * (-15137LL);
    dataptr[2] = (DCTELEM)(((z1 + z2 + (1LL << 10)) >> 11));
    dataptr[6] = (DCTELEM)(((z1 + z3 + (1LL << 10)) >> 11));

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = (z3 + z4) * 9633LL;

    tmp4 = tmp4 * 2446LL;
    tmp5 = tmp5 * 16819LL;
    tmp6 = tmp6 * 25172LL;
    tmp7 = tmp7 * 12299LL;

    z1 = z1 * (-7373LL);
    z2 = z2 * (-20995LL);
    z3 = z3 * (-16069LL);
    z4 = z4 * (-3196LL);

    z3 += z5;
    z4 += z5;

    dataptr[7] = (DCTELEM)(((tmp4 + z1 + z3 + (1LL << 10)) >> 11));
    dataptr[5] = (DCTELEM)(((tmp5 + z2 + z4 + (1LL << 10)) >> 11));
    dataptr[3] = (DCTELEM)(((tmp6 + z2 + z3 + (1LL << 10)) >> 11));
    dataptr[1] = (DCTELEM)(((tmp7 + z1 + z4 + (1LL << 10)) >> 11));

    dataptr += 8;
}
}
