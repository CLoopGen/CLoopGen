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
extern INT32 z1;
extern INT32 z2;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 4 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 0];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 7];
    tmp2 = dataptr[8 * 2] + dataptr[8 * 6];
    tmp3 = dataptr[8 * 3] + dataptr[8 * 5];
    tmp4 = dataptr[8 * 4];
    tmp10 = dataptr[8 * 0] - wsptr[8 * 0];
    tmp11 = dataptr[8 * 1] - dataptr[8 * 7];
    tmp12 = dataptr[8 * 2] - dataptr[8 * 6];
    tmp13 = dataptr[8 * 3] - dataptr[8 * 5];

    z1 = tmp0 + tmp2;
    z2 = tmp1 + tmp4;
    dataptr[8 * 0] = (DCTELEM)((((z1 + tmp3 + z2) * (((INT32)((1.5802469139999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 6] = (DCTELEM)((((z1 + tmp3 - z2 - z2) * (((INT32)((1.117403309) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 14)) >> 15);

    z1 = ((tmp0 - tmp2) * (((INT32)((2.1000312870000002) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp1 - tmp4 - tmp4) * (((INT32)((1.117403309) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 2] = (DCTELEM)((((tmp2 - tmp3) * (((INT32)((1.71196119) * (((INT32)1) << 13) + 0.5)))) + z1 + z2 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 4] = (DCTELEM)((((tmp3 - tmp0) * (((INT32)((0.38807009599999998) * (((INT32)1) << 13) + 0.5)))) + z1 - z2 + ((INT32)1 << 14)) >> 15);

    dataptr[8 * 3] = (DCTELEM)((((tmp10 - tmp12) - tmp13) * (((INT32)((1.9353993030000001) * (((INT32)1) << 13) + 0.5))) + ((INT32)1 << 14)) >> 15);

    tmp11 = tmp11 * (((INT32)((1.9353993030000001) * (((INT32)1) << 13) + 0.5)));
    tmp0 = (tmp10 + tmp12) * (((INT32)((1.4365060039999999) * (((INT32)1) << 13) + 0.5)));
    tmp1 = (tmp10 + tmp13) * (((INT32)((0.76434887900000004) * (((INT32)1) << 13) + 0.5)));

    dataptr[8 * 1] = (DCTELEM)((tmp11 + tmp0 + tmp1 + ((INT32)1 << 14)) >> 15);
    tmp2 = (tmp12 - tmp13) * (((INT32)((2.2008548829999999) * (((INT32)1) << 13) + 0.5)));
    dataptr[8 * 5] = (DCTELEM)((tmp0 - tmp11 - tmp2 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 7] = (DCTELEM)((tmp1 - tmp11 + tmp2 + ((INT32)1 << 14)) >> 15);

    dataptr++;
    wsptr++;
}
}
