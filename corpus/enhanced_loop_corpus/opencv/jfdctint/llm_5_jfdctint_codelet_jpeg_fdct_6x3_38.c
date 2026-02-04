#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    // Remove some RAW dependencies by precomputing differences before sums
    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[5]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[4]));
    tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[3]));
    // Eliminate WAW hazard on tmp0/tmp2 by using distinct temporaries for sum and diff
    INT32 sum0_5 = ((int)(elemptr[0])) + ((int)(elemptr[5]));
    INT32 sum1_4 = ((int)(elemptr[1])) + ((int)(elemptr[4]));
    INT32 sum2_3 = ((int)(elemptr[2])) + ((int)(elemptr[3]));
    INT32 sum10 = sum0_5 + sum2_3;
    INT32 sum12 = sum0_5 - sum2_3;

    dataptr[0] = (DCTELEM)((sum10 + sum1_4 - 6 * 128) << (2 + 1));
    dataptr[2] = (DCTELEM)(((((sum12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
    dataptr[4] = (DCTELEM)(((((sum10 - sum1_4 - sum1_4) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
    INT32 tmp10_val = (((((tmp0 + tmp2) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
    dataptr[1] = (DCTELEM)(tmp10_val + ((tmp0 + tmp1) << (2 + 1)));
    dataptr[3] = (DCTELEM)((tmp0 - tmp1 - tmp2) << (2 + 1));
    dataptr[5] = (DCTELEM)(tmp10_val + ((tmp2 - tmp1) << (2 + 1)));
    dataptr += 8;
}
}
