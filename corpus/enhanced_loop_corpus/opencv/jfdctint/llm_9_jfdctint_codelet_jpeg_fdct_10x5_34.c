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
INT32 tmp_buffer[5][8];
for (ctr = 0; ctr < 5; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    INT32 a0 = ((int)(elemptr[0])), a1 = ((int)(elemptr[1])), a2 = ((int)(elemptr[2]));
    INT32 a3 = ((int)(elemptr[3])), a4 = ((int)(elemptr[4])), a5 = ((int)(elemptr[5]));
    INT32 a6 = ((int)(elemptr[6])), a7 = ((int)(elemptr[7])), a8 = ((int)(elemptr[8]));
    INT32 a9 = ((int)(elemptr[9]));

    INT32 s0 = a0 + a9, s1 = a1 + a8, s2 = a2 + a7, s3 = a3 + a6, s4 = a4 + a5;
    INT32 d0 = a0 - a9, d1 = a1 - a8, d2 = a2 - a7, d3 = a3 - a6, d4 = a4 - a5;

    INT32 sum04 = s0 + s4, dif04 = s0 - s4;
    INT32 sum13 = s1 + s3, dif13 = s1 - s3;

    tmp_buffer[ctr][0] = (DCTELEM)((sum04 + sum13 + s2 - 1280) << 2);

    INT32 scaled_s2 = s2 << 1;
    INT32 coef1 = ((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5));
    INT32 coef2 = ((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5));
    tmp_buffer[ctr][4] = (DCTELEM)((((sum04 - scaled_s2) * coef1 - (sum13 - scaled_s2) * coef2) + 1024) >> 11);

    INT32 mix_temp = (dif04 + dif13) * ((INT32)(0.831253876 * (1<<13) + 0.5));
    INT32 coef3 = ((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5));
    INT32 coef4 = ((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5));
    tmp_buffer[ctr][2] = (DCTELEM)(((mix_temp + dif04 * coef3) + 1024) >> 11);
    tmp_buffer[ctr][6] = (DCTELEM)(((mix_temp - dif13 * coef4) + 1024) >> 11);

    INT32 vsum = d0 + d4, vdif = d1 - d3;
    tmp_buffer[ctr][5] = (DCTELEM)((vsum - vdif - d2) << 2);

    d2 <<= 13;
    INT32 coef5 = ((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5));
    INT32 coef6 = ((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5));
    INT32 coef7 = ((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5));
    INT32 coef8 = ((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5));
    tmp_buffer[ctr][1] = (DCTELEM)((((d0 * coef5) + (d1 * coef6) + d2 + (d3 * coef7) + (d4 * coef8)) + 1024) >> 11);

    INT32 pA = (d0 - d4) * ((INT32)(0.95105651599999996 * (1<<13) + 0.5));
    INT32 pB = (d1 + d3) * ((INT32)(0.58778525199999998 * (1<<13) + 0.5));
    INT32 wsum = vsum + vdif;
    INT32 mterm = (wsum * ((INT32)(0.30901699399999999 * (1<<13) + 0.5))) + (vdif << 12) - d2;

    tmp_buffer[ctr][3] = (DCTELEM)(((pA - pB + mterm) + 1024) >> 11);
    tmp_buffer[ctr][7] = (DCTELEM)(((pA - pB - mterm) + 1024) >> 11);
}

for (ctr = 0; ctr < 5; ctr++) {
    for (int j = 0; j < 8; j++) {
        dataptr[ctr * 8 + j] = tmp_buffer[ctr][j];
    }
}

}
