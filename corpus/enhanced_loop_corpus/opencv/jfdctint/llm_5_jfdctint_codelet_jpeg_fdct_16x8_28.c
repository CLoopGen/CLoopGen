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
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp17;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    if (ctr == 0 || ctr == 7) {
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[15]));
        tmp7 = ((int)(elemptr[7])) + ((int)(elemptr[8]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[14]));
        tmp6 = ((int)(elemptr[6])) + ((int)(elemptr[9]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[13]));
        tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[10]));
        tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[12]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[11]));

        tmp10 = tmp0 + tmp7;
        tmp14 = tmp0 - tmp7;
        tmp11 = tmp1 + tmp6;
        tmp15 = tmp1 - tmp6;
        tmp12 = tmp2 + tmp5;
        tmp16 = tmp2 - tmp5;
        tmp13 = tmp3 + tmp4;
        tmp17 = tmp3 - tmp4;
    } else if (ctr == 1 || ctr == 6) {
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[15])) + 1;
        tmp7 = ((int)(elemptr[7])) + ((int)(elemptr[8])) - 1;
        tmp10 = tmp0 + tmp7;
        tmp14 = tmp0 - tmp7;
        tmp11 = tmp12 = tmp13 = 0;
        tmp15 = tmp16 = tmp17 = 0;
    } else {
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[15]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[14]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[13]));
        tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[12]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[11]));
        tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[10]));
        tmp6 = ((int)(elemptr[6])) + ((int)(elemptr[9]));
        tmp7 = ((int)(elemptr[7])) + ((int)(elemptr[8]));

        tmp10 = tmp1 + tmp6;
        tmp14 = tmp2 - tmp5;
        tmp11 = tmp0 + tmp7;
        tmp15 = tmp3 - tmp4;
        tmp12 = tmp13 = tmp16 = tmp17 = 0;
    }

    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[15]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[14]));
    tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[13]));
    tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[12]));
    tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[11]));
    tmp5 = ((int)(elemptr[5])) - ((int)(elemptr[10]));
    tmp6 = ((int)(elemptr[6])) - ((int)(elemptr[9]));
    tmp7 = ((int)(elemptr[7])) - ((int)(elemptr[8]));

    dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 - 16 * 128) << 2);

    if (ctr < 2 || ctr > 5) {
        dataptr[4] = (DCTELEM)(((((tmp10 - tmp13) * 10868)) + ((tmp11 - tmp12) * 4433) + ((INT32)1 << 10)) >> 11);
        tmp10 = ((tmp17 - tmp15) * 2270) + ((tmp14 - tmp16) * 11380);
        dataptr[2] = (DCTELEM)(((tmp10 + ((tmp15) * 12000) + ((tmp16) * 18000)) + 1024) >> 11);
        dataptr[6] = (DCTELEM)(((tmp10 - ((tmp14) * 175) - ((tmp17) * 8750)) + 1024) >> 11);
    } else {
        dataptr[4] = (DCTELEM)((tmp10 * 8192 + 1024) >> 11);
        tmp10 = (tmp14 + tmp16) * 2048;
        dataptr[2] = (DCTELEM)((tmp10 + 1024) >> 11);
        dataptr[6] = (DCTELEM)(((tmp10 >> 2) + 1024) >> 11);
    }

    if (ctr != 3 && ctr != 4) {
        tmp11 = ((tmp0 + tmp1) * 11125) + ((tmp6 - tmp7) * 3360);
        tmp12 = ((tmp0 + tmp2) * 10240) + ((tmp5 + tmp7) * 5470);
        tmp13 = ((tmp0 + tmp3) * 9000) + ((tmp4 - tmp7) * 7360);
        tmp14 = ((tmp1 + tmp2) * 1140) + ((tmp6 - tmp5) * 11560);
        tmp15 = ((tmp1 + tmp3) * (-5470)) + ((tmp4 + tmp6) * (-10240));
        tmp16 = ((tmp2 + tmp3) * (-11125)) + ((tmp5 - tmp4) * 3360);

        tmp10 = tmp11 + tmp12 + tmp13 - (tmp0 * 18800) + (tmp7 * 6400);
        tmp11 += tmp14 + tmp15 + (tmp1 * 590) - (tmp6 * 13680);
        tmp12 += tmp14 + tmp16 - (tmp2 * 9250) + (tmp5 * 10100);
        tmp13 += tmp15 + tmp16 + (tmp3 * 8750) + (tmp4 * 17800);
    } else {
        tmp11 = tmp0 * 12000 + tmp1 * 3000;
        tmp12 = tmp0 * 10000 + tmp2 * 5000;
        tmp13 = tmp0 * 8000 + tmp3 * 7000;
        tmp14 = tmp1 * 1000 + tmp2 * 2000;
        tmp15 = tmp1 * 6000 + tmp3 * 4000;
        tmp16 = tmp2 * 9000 + tmp3 * 1000;

        tmp10 = tmp11 + tmp12 + tmp13 - tmp0 * 18000;
        tmp11 = tmp11 + tmp14 + tmp15;
        tmp12 = tmp12 + tmp14 + tmp16;
        tmp13 = tmp13 + tmp15 + tmp16;
    }

    dataptr[1] = (DCTELEM)(((tmp10) + 1024) >> 11);
    dataptr[3] = (DCTELEM)(((tmp11) + 1024) >> 11);
    dataptr[5] = (DCTELEM)(((tmp12) + 1024) >> 11);
    dataptr[7] = (DCTELEM)(((tmp13) + 1024) >> 11);
    dataptr += 8;
}
}
