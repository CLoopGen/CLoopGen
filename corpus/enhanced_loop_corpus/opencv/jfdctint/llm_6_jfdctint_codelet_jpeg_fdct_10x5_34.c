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
extern INT32 tmp4;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ++ctr) {
    elemptr = sample_data[ctr] + start_col;

    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[9]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[8]));
    tmp12 = ((int)(elemptr[2])) + ((int)(elemptr[7]));
    tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[6]));
    tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[5]));

    tmp10 = tmp0 + tmp4;
    tmp13 = tmp0 - tmp4;
    tmp11 = tmp1 + tmp3;
    tmp14 = tmp1 - tmp3;

    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[9]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[8]));
    tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[7]));
    tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[6]));
    tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[5]));

    // Conditional skip: only process full transform on even iterations
    if (ctr % 2 == 0) {
        dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 - 10 * 128) << 2);
        tmp12 += tmp12;
        dataptr[4] = (DCTELEM)(((((tmp10 - tmp12) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp11 - tmp12) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    } else {
        // Simplified path for odd indices
        dataptr[0] = (DCTELEM)(tmp10 << 2);
        dataptr[4] = (DCTELEM)(tmp11 << 2);
    }

    tmp10 = ((tmp13 + tmp14) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    dataptr[2] = (DCTELEM)(((tmp10 + ((tmp13) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[6] = (DCTELEM)(((tmp10 - ((tmp14) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    tmp10 = tmp0 + tmp4;
    tmp11 = tmp1 - tmp3;

    // Alternate computation based on sign
    if (tmp1 > 0) {
        dataptr[5] = (DCTELEM)((tmp10 - tmp11 - tmp2) << 2);
    } else {
        dataptr[5] = (DCTELEM)((-tmp10 + tmp11 - tmp2) << 2);
    }

    tmp2 <<= 13;
    dataptr[1] = (DCTELEM)(((((tmp0) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) + tmp2 + ((tmp3) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    tmp12 = ((tmp0 - tmp4) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5)))) - ((tmp1 + tmp3) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = ((tmp10 + tmp11) * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5)))) + (tmp11 << (13 - 1)) - tmp2;

    // Skip less critical outputs on last iteration
    if (ctr != 4) {
        dataptr[3] = (DCTELEM)(((tmp12 + tmp13) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[7] = (DCTELEM)(((tmp12 - tmp13) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    } else {
        dataptr[3] = 0;
        dataptr[7] = 0;
    }

    dataptr += 8;
}
}
