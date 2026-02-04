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
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern DCTELEM workspace[64];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int access_idx = 0; access_idx < 8; access_idx++) {
    int row_order[] = {0, 2, 4, 6, 7, 5, 3, 1}; // Non-consecutive, indirect access pattern
    int i = row_order[access_idx];
    elemptr = sample_data[i] + start_col;
    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[7]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[6]));
    tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[5]));
    tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[4]));
    tmp10 = tmp0 + tmp3;
    tmp12 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp13 = tmp1 - tmp2;
    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[7]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[6]));
    tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[5]));
    tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[4]));
    dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 8 * 128) << 2);
    dataptr[4] = (DCTELEM)((tmp10 - tmp11) << 2);
    z1 = ((tmp12 + tmp13) * (((INT32)4433)));
    dataptr[2] = (DCTELEM)(((z1 + ((tmp12) * (((INT32)6270)))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[6] = (DCTELEM)(((z1 - ((tmp13) * (((INT32)15137)))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    tmp12 = tmp0 + tmp2;
    tmp13 = tmp1 + tmp3;
    z1 = ((tmp12 + tmp13) * (((INT32)9633)));
    tmp12 = ((tmp12) * (-((INT32)3196)));
    tmp13 = ((tmp13) * (-((INT32)16069)));
    tmp12 += z1;
    tmp13 += z1;
    z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
    tmp0 = ((tmp0) * (((INT32)12299)));
    tmp3 = ((tmp3) * (((INT32)2446)));
    tmp0 += z1 + tmp12;
    tmp3 += z1 + tmp13;
    z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
    tmp1 = ((tmp1) * (((INT32)25172)));
    tmp2 = ((tmp2) * (((INT32)16819)));
    tmp1 += z1 + tmp13;
    tmp2 += z1 + tmp12;
    dataptr[1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr += 8;
    if (access_idx == 7)
        break;
}
ctr = 8 * 2; // Simulate final state of outer logic
}
