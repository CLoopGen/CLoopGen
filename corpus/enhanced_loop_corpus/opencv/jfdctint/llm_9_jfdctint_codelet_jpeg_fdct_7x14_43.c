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
extern INT32 tmp16;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++) {
    tmp0 = dataptr[8 * 0] + wsptr[8 * 5];
    tmp1 = dataptr[8 * 1] + wsptr[8 * 4];
    tmp2 = dataptr[8 * 2] + wsptr[8 * 3];
    tmp13 = dataptr[8 * 3] + wsptr[8 * 2];
    tmp4 = dataptr[8 * 4] + wsptr[8 * 1];
    tmp5 = dataptr[8 * 5] + wsptr[8 * 0];
    tmp6 = dataptr[8 * 6] + dataptr[8 * 7];
    tmp10 = tmp0 + tmp6;
    tmp14 = tmp0 - tmp6;
    tmp11 = tmp1 + tmp5;
    tmp15 = tmp1 - tmp5;
    tmp12 = tmp2 + tmp4;
    tmp16 = tmp2 - tmp4;

    // Reduced precision and simplified computation for lower intensity
    dataptr[8 * 0] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 + 2) >> 2);
    dataptr[8 * 4] = (DCTELEM)((tmp10 - tmp13 + 1) >> 1);
    dataptr[8 * 2] = (DCTELEM)((tmp14 + tmp15 + 1) >> 1);
    dataptr[8 * 6] = (DCTELEM)((tmp14 - tmp15 + 1) >> 1);

    tmp10 = tmp1 + tmp2;
    tmp11 = tmp5 - tmp4;
    dataptr[8 * 7] = (DCTELEM)((tmp0 - tmp10 + tmp3 - tmp11 - tmp6 + 2) >> 2);

    tmp11 = (tmp0 + tmp2 + tmp4 + tmp6) >> 1;
    dataptr[8 * 5] = (DCTELEM)((tmp10 + tmp11) >> 1);

    tmp12 = (tmp0 + tmp1 + tmp5 - tmp6) >> 1;
    dataptr[8 * 3] = (DCTELEM)((tmp10 + tmp12) >> 1);

    dataptr[8 * 1] = (DCTELEM)((tmp11 + tmp12 + 1) >> 1);

    dataptr++;
    wsptr++;
}
}
