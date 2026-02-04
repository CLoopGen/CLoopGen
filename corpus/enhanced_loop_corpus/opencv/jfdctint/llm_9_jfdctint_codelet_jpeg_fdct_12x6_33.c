#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr -= 2) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 5];
    tmp11 = dataptr[8 * 1] + dataptr[8 * 4];
    tmp2 = dataptr[8 * 2] + dataptr[8 * 3];
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    tmp0 = dataptr[8 * 0] - dataptr[8 * 5];
    tmp1 = dataptr[8 * 1] - dataptr[8 * 4];
    tmp2 = dataptr[8 * 2] - dataptr[8 * 3];

    INT32 factor1 = (INT32)(1.7777777779999999 * ((INT32)1 << 13) + 0.5);
    INT32 factor2 = (INT32)(2.1773242160000001 * ((INT32)1 << 13) + 0.5);
    INT32 factor3 = (INT32)(1.2570787219999999 * ((INT32)1 << 13) + 0.5);
    INT32 factor4 = (INT32)(0.65071182900000002 * ((INT32)1 << 13) + 0.5);
    INT32 shift = (INT32)1 << 14;

    dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11) * factor1) + shift) >> 15);
    dataptr[8 * 2] = (DCTELEM)(((tmp12 * factor2) + shift) >> 15);
    dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp11 - tmp11) * factor3) + shift) >> 15);

    tmp10 = (tmp0 + tmp2) * factor4;
    INT32 termA = (tmp0 + tmp1) * factor1;
    INT32 termB = (tmp2 - tmp1) * factor1;

    dataptr[8 * 1] = (DCTELEM)(((tmp10 + termA) + shift) >> 15);
    dataptr[8 * 3] = (DCTELEM)((((tmp0 - tmp1 - tmp2) * factor1) + shift) >> 15);
    dataptr[8 * 5] = (DCTELEM)(((tmp10 + termB) + shift) >> 15);

    if (ctr > 1) {
        DCTELEM* next_dataptr = dataptr + 1;
        tmp0 = next_dataptr[8 * 0] + next_dataptr[8 * 5];
        tmp11 = next_dataptr[8 * 1] + next_dataptr[8 * 4];
        tmp2 = next_dataptr[8 * 2] + next_dataptr[8 * 3];
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;
        tmp0 = next_dataptr[8 * 0] - next_dataptr[8 * 5];
        tmp1 = next_dataptr[8 * 1] - next_dataptr[8 * 4];
        tmp2 = next_dataptr[8 * 2] - next_dataptr[8 * 3];

        next_dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11) * factor1) + shift) >> 15);
        next_dataptr[8 * 2] = (DCTELEM)(((tmp12 * factor2) + shift) >> 15);
        next_dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp11 - tmp11) * factor3) + shift) >> 15);

        tmp10 = (tmp0 + tmp2) * factor4;
        termA = (tmp0 + tmp1) * factor1;
        termB = (tmp2 - tmp1) * factor1;

        next_dataptr[8 * 1] = (DCTELEM)(((tmp10 + termA) + shift) >> 15);
        next_dataptr[8 * 3] = (DCTELEM)((((tmp0 - tmp1 - tmp2) * factor1) + shift) >> 15);
        next_dataptr[8 * 5] = (DCTELEM)(((tmp10 + termB) + shift) >> 15);
    }
    dataptr += 2;
}
}
