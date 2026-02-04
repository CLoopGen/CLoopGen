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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern DCTELEM workspace[32];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (int inner = 0; inner < 8; inner++) {
        int idx = outer * 8 + inner;
        if (idx >= 12) break;

        elemptr = sample_data[idx] + start_col;

        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[11]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[10]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[9]));
        tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[8]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[7]));
        tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[6]));

        tmp10 = tmp0 + tmp5;
        tmp13 = tmp0 - tmp5;
        tmp11 = tmp1 + tmp4;
        tmp14 = tmp1 - tmp4;
        tmp12 = tmp2 + tmp3;
        tmp15 = tmp2 - tmp3;

        DCTELEM* local_dataptr = (inner == 0 && outer > 0) ? workspace : workspace + inner * 8;

        local_dataptr[0] = (DCTELEM)(tmp10 + tmp11 + tmp12 - 12 * 128);
        local_dataptr[6] = (DCTELEM)(tmp13 - tmp14 - tmp15);

        const INT32 shift = 13;
        INT32 coef_12247 = ((INT32)(1.224744871 * (1 << shift) + 0.5));
        INT32 coef_13660 = ((INT32)(1.3660254039999999 * (1 << shift) + 0.5));

        local_dataptr[4] = (DCTELEM)((((tmp10 - tmp12) * coef_12247) + (1 << (shift - 1))) >> shift);
        local_dataptr[2] = (DCTELEM)(((tmp14 - tmp15 + (tmp13 + tmp15) * coef_13660) + (1 << (shift - 1))) >> shift);

        tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[11]));
        tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[10]));
        tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[9]));
        tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[8]));
        tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[7]));
        tmp5 = ((int)(elemptr[5])) - ((int)(elemptr[6]));

        INT32 t10 = (tmp1 + tmp4) * 4433;
        INT32 t14 = t10 + tmp1 * 6270;
        INT32 t15 = t10 - tmp4 * 15137;

        INT32 u1 = (tmp0 + tmp2) * ((INT32)(1.1219710540000001 * (1 << shift) + 0.5));
        INT32 u2 = (tmp0 + tmp3) * ((INT32)(0.86091866900000003 * (1 << shift) + 0.5));

        INT32 v1 = ((INT32)(0.58077495300000004 * (1 << shift) + 0.5));
        INT32 v2 = ((INT32)(0.184591911 * (1 << shift) + 0.5));
        INT32 v3 = ((INT32)(2.339493912 * (1 << shift) + 0.5));
        INT32 v4 = ((INT32)(0.72578801100000001 * (1 << shift) + 0.5));
        INT32 v5 = ((INT32)(1.3065629649999999 * (1 << shift) + 0.5));

        INT32 res0 = u1 + u2 + t14 - tmp0 * v1 + tmp5 * v2;
        INT32 res1 = (tmp2 + tmp3) * (-v2);
        INT32 res2 = u1 + res1 - t15 - tmp2 * v3 + tmp5 * ((INT32)(0.86091866900000003 * (1 << shift) + 0.5));
        INT32 res3 = u2 + res1 - t14 + tmp3 * v4 - tmp5 * ((INT32)(1.1219710540000001 * (1 << shift) + 0.5));
        INT32 res4 = t15 + (tmp0 - tmp3) * v5 - (tmp2 + tmp5) * 4433;

        local_dataptr[1] = (DCTELEM)((res0 + (1 << (shift - 1))) >> shift);
        local_dataptr[3] = (DCTELEM)((res4 + (1 << (shift - 1))) >> shift);
        local_dataptr[5] = (DCTELEM)((res2 + (1 << (shift - 1))) >> shift);
        local_dataptr[7] = (DCTELEM)((res3 + (1 << (shift - 1))) >> shift);
    }
    if (outer * 8 + 8 >= 12) break;
}
ctr = 12;
dataptr = workspace + 8;
}
