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
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr += 1) {
    for (int block = 0; block < 2; ++block) {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 4];
        tmp1 = dataptr[8 * 1] + dataptr[8 * 3];
        tmp2 = dataptr[8 * 2];
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp0 = dataptr[8 * 0] - dataptr[8 * 4];
        tmp1 = dataptr[8 * 1] - dataptr[8 * 3];

        const INT32 shift = 13 + 2;
        const INT32 round = (INT32)1 << (shift - 1);

        INT32 base_val = tmp10 + tmp2;
        dataptr[8 * 0] = (DCTELEM)(((base_val * 10496) + round) >> shift); // approx 1.28 * 2^13

        tmp11 = (tmp11 * 8292); // approx 1.011928851 * 2^13
        tmp10 = (tmp10 - (tmp2 << 2)) * 3711; // approx 0.4525 * 2^13

        dataptr[8 * 2] = (DCTELEM)(((tmp11 + tmp10) + round) >> shift);
        dataptr[8 * 4] = (DCTELEM)(((tmp11 - tmp10) + round) >> shift);

        tmp10 = (tmp0 + tmp1) * 8727; // approx 1.064 * 2^13
        dataptr[8 * 1] = (DCTELEM)(((tmp10 + (tmp0 * 5386)) + round) >> shift); // 0.6576 * 2^13
        dataptr[8 * 3] = (DCTELEM)(((tmp10 - (tmp1 * 22825)) + round) >> shift); // 2.7856 * 2^13

        dataptr++;
    }
}
}
