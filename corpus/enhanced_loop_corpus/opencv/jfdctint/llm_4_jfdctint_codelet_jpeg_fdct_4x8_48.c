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
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr += 2) {
    JSAMPROW elemptr0 = sample_data[ctr + 0] + start_col;
    JSAMPROW elemptr1 = sample_data[ctr + 1] + start_col;
    INT32 tmp0_0, tmp1_0, tmp10_0, tmp11_0;
    INT32 tmp0_1, tmp1_1, tmp10_1, tmp11_1;

    tmp0_0 = ((int)(elemptr0[0])) + ((int)(elemptr0[3]));
    tmp1_0 = ((int)(elemptr0[1])) + ((int)(elemptr0[2]));
    tmp10_0 = ((int)(elemptr0[0])) - ((int)(elemptr0[3]));
    tmp11_0 = ((int)(elemptr0[1])) - ((int)(elemptr0[2]));

    tmp0_1 = ((int)(elemptr1[0])) + ((int)(elemptr1[3]));
    tmp1_1 = ((int)(elemptr1[1])) + ((int)(elemptr1[2]));
    tmp10_1 = ((int)(elemptr1[0])) - ((int)(elemptr1[3]));
    tmp11_1 = ((int)(elemptr1[1])) - ((int)(elemptr1[2]));

    DCTELEM* dp0 = dataptr + (ctr + 0) * 8;
    DCTELEM* dp1 = dataptr + (ctr + 1) * 8;

    dp0[0] = (DCTELEM)(((tmp0_0 + tmp1_0 - 4 * 128) << (2 + 1)));
    dp0[2] = (DCTELEM)(((tmp0_0 - tmp1_0) << (2 + 1)));
    tmp0_0 = ((tmp10_0 + tmp11_0) * (((INT32)4433)));
    tmp0_0 += ((INT32)1) << (13 - 2 - 2);
    dp0[1] = (DCTELEM)((tmp0_0 + ((tmp10_0) * (((INT32)6270)))) >> (13 - 2 - 1));
    dp0[3] = (DCTELEM)((tmp0_0 - ((tmp11_0) * (((INT32)15137)))) >> (13 - 2 - 1));

    dp1[0] = (DCTELEM)(((tmp0_1 + tmp1_1 - 4 * 128) << (2 + 1)));
    dp1[2] = (DCTELEM)(((tmp0_1 - tmp1_1) << (2 + 1)));
    tmp0_1 = ((tmp10_1 + tmp11_1) * (((INT32)4433)));
    tmp0_1 += ((INT32)1) << (13 - 2 - 2);
    dp1[1] = (DCTELEM)((tmp0_1 + ((tmp10_1) * (((INT32)6270)))) >> (13 - 2 - 1));
    dp1[3] = (DCTELEM)((tmp0_1 - ((tmp11_1) * (((INT32)15137)))) >> (13 - 2 - 1));
}
}
