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
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ++ctr) {
    elemptr = sample_data[ctr] + start_col;

    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[4]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[3]));
    tmp2 = ((int)(elemptr[2]));

    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;

    if (tmp11 < 0) continue;

    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[4]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[3]));

    if (tmp0 == 0 && tmp1 == 0) {
        dataptr[0] = (DCTELEM)((tmp10 + tmp2 - 5 * 128) << (2 + 1));
        dataptr[1] = dataptr[3] = 0;
        dataptr[2] = dataptr[4] = 0;
    } else {
        dataptr[0] = (DCTELEM)((tmp10 + tmp2 - 5 * 128) << (2 + 1));

        tmp11 = ((tmp11) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        tmp10 -= tmp2 << 2;
        tmp10 = ((tmp10) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));

        dataptr[2] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        dataptr[4] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));

        tmp10 = ((tmp0 + tmp1) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        dataptr[1] = (DCTELEM)(((tmp10 + ((tmp0) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        dataptr[3] = (DCTELEM)(((tmp10 - ((tmp1) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
    }

    dataptr += 8;
}
}
