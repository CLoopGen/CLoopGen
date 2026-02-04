#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++) {
    // Unroll original loop body twice and fuse operations
    // First iteration
    tmp0 = dataptr[8 * 0] + dataptr[8 * 2];
    tmp1 = dataptr[8 * 1];
    tmp2 = dataptr[8 * 0] - dataptr[8 * 2];
    dataptr[8 * 0] = (DCTELEM)((((tmp0 + tmp1) * 14586) + 16384) >> 15);
    dataptr[8 * 2] = (DCTELEM)((((tmp0 - tmp1 - tmp1) * 10307) + 16384) >> 15);
    dataptr[8 * 1] = (DCTELEM)(((tmp2 * 17826) + 16384) >> 15);
    dataptr++;

    // Second iteration (unrolled)
    tmp0 = dataptr[8 * 0] + dataptr[8 * 2];
    tmp1 = dataptr[8 * 1];
    tmp2 = dataptr[8 * 0] - dataptr[8 * 2];
    dataptr[8 * 0] = (DCTELEM)((((tmp0 + tmp1) * 14586) + 16384) >> 15);
    dataptr[8 * 2] = (DCTELEM)((((tmp0 - tmp1 - tmp1) * 10307) + 16384) >> 15);
    dataptr[8 * 1] = (DCTELEM)(((tmp2 * 17826) + 16384) >> 15);
    dataptr++;
}
}
