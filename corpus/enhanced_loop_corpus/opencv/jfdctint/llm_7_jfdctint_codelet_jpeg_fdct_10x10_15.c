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



void loop() {
    for (ctr = 16 - 1; ctr >= 0; ctr -= 2) {
        for (int unroll = 0; unroll < 2; ++unroll) {
            if (ctr - unroll < 0) continue;

            tmp0 = dataptr[8 * 0] + wsptr[8 * 1];
            tmp1 = dataptr[8 * 1] + wsptr[8 * 0];
            tmp12 = dataptr[8 * 2] + dataptr[8 * 7];
            tmp3 = dataptr[8 * 3] + dataptr[8 * 6];
            tmp4 = dataptr[8 * 4] + dataptr[8 * 5];
            tmp10 = tmp0 + tmp4;
            tmp13 = tmp0 - tmp4;
            tmp11 = tmp1 + tmp3;
            tmp14 = tmp1 - tmp3;
            tmp0 = dataptr[8 * 0] - wsptr[8 * 1];
            tmp1 = dataptr[8 * 1] - wsptr[8 * 0];
            tmp2 = dataptr[8 * 2] - dataptr[8 * 7];
            tmp3 = dataptr[8 * 3] - dataptr[8 * 6];
            tmp4 = dataptr[8 * 4] - dataptr[8 * 5];

            INT32 factor1 = ((INT32)((1.28) * (((INT32)1) << 13) + 0.5));
            INT32 factor2 = ((INT32)((1.464477191) * (((INT32)1) << 13) + 0.5));
            INT32 factor3 = ((INT32)((0.559380511) * (((INT32)1) << 13) + 0.5));
            INT32 factor4 = ((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5));
            INT32 factor5 = ((INT32)((2.785601151) * (((INT32)1) << 13) + 0.5));

            dataptr[8 * 0] = (DCTELEM)(((tmp10 + tmp11 + tmp12) * factor1 + (INT32)1 << 14) >> 15);
            dataptr[8 * 4] = (DCTELEM)(((tmp10 - tmp12) * factor2 - (tmp11 - tmp12) * factor3 + (INT32)1 << 14) >> 15);
            dataptr[8 * 2] = (DCTELEM)(((tmp13 + tmp14) * factor4 + tmp13 * (factor4 >> 1) + (INT32)1 << 14) >> 15);
            dataptr[8 * 6] = (DCTELEM)(((tmp13 + tmp14) * factor4 - tmp14 * factor5 + (INT32)1 << 14) >> 15);

            tmp10 = tmp0 + tmp4;
            tmp11 = tmp1 - tmp3;
            dataptr[8 * 5] = (DCTELEM)(((tmp10 - tmp11 - tmp2) * factor1 + (INT32)1 << 14) >> 15);
            INT32 base_val = tmp0 * ((INT32)(1.7879 * (1<<13)+0.5)) +
                             tmp1 * ((INT32)(1.6129 * (1<<13)+0.5)) +
                             tmp2 * ((INT32)(1.28 * (1<<13)+0.5)) +
                             tmp3 * ((INT32)(0.8218 * (1<<13)+0.5)) +
                             tmp4 * ((INT32)(0.2832 * (1<<13)+0.5)) + (INT32)1 << 14;
            dataptr[8 * 1] = (DCTELEM)(base_val >> 15);

            tmp12 = (tmp0 - tmp4) * ((INT32)(1.21735 * (1<<13)+0.5)) - (tmp1 + tmp3) * ((INT32)(0.752365 * (1<<13)+0.5));
            tmp13 = (tmp10 + tmp11) * ((INT32)(0.39554 * (1<<13)+0.5)) + tmp11 * ((INT32)(0.64 * (1<<13)+0.5)) - tmp2 * ((INT32)(1.28 * (1<<13)+0.5));
            dataptr[8 * 3] = (DCTELEM)((tmp12 + tmp13 + (INT32)1 << 14) >> 15);
            dataptr[8 * 7] = (DCTELEM)((tmp12 - tmp13 + (INT32)1 << 14) >> 15);

            dataptr++;
            wsptr++;
        }
    }
}
