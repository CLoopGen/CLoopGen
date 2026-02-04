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
for (ctr = 0; ctr < 5; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[4]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[3]));
    tmp2 = ((int)(elemptr[2]));
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[4]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[3]));
    dataptr[0] = (DCTELEM)((tmp10 + tmp2 - 5 * 128) << (2 + 1));
    INT32 temp_mult_790569 = ((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5));
    INT32 temp_mult_353553 = ((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5));
    tmp11 = ((tmp11) * temp_mult_790569);
    tmp10 -= tmp2 << 2;
    tmp10 = ((tmp10) * temp_mult_353553);
    int shift_val = 13 - 2 - 1;
    dataptr[2] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << (shift_val - 1))) >> shift_val);
    dataptr[4] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << (shift_val - 1))) >> shift_val);
    INT32 coef_831253 = ((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5));
    INT32 coef_513743 = ((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5));
    INT32 coef_217625 = ((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5));
    tmp10 = ((tmp0 + tmp1) * coef_831253);
    dataptr[1] = (DCTELEM)(((tmp10 + (tmp0 * coef_513743)) + ((INT32)1 << (shift_val - 1))) >> shift_val);
    dataptr[3] = (DCTELEM)(((tmp10 - (tmp1 * coef_217625)) + ((INT32)1 << (shift_val - 1))) >> shift_val);
    dataptr += 8;
}
}
