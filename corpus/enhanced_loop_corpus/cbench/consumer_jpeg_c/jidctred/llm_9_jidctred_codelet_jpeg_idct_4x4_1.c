#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++) {
    outptr = output_buf[ctr & 3] + output_col;
    tmp0 = ((INT32)wsptr[0]) << (13 + 1);
    tmp2 = (((INT32)wsptr[2]) * (((INT32)15137))) + (((INT32)wsptr[6]) * (-((INT32)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (INT32)wsptr[7];
    z2 = (INT32)wsptr[5];
    z3 = (INT32)wsptr[3];
    z4 = (INT32)wsptr[1];
    tmp0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
    tmp2 = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
    INT32 sum1 = tmp10 + tmp2;
    INT32 diff1 = tmp10 - tmp2;
    INT32 sum2 = tmp12 + tmp0;
    INT32 diff2 = tmp12 - tmp0;
    INT32 shift = (13 + 2 + 3 + 1);
    outptr[0] = range_limit[(int)((sum1 + (((INT32)1) << (shift - 1))) >> shift) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)((diff1 + (((INT32)1) << (shift - 1))) >> shift) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)((sum2 + (((INT32)1) << (shift - 1))) >> shift) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)((diff2 + (((INT32)1) << (shift - 1))) >> shift) & (255 * 4 + 3)];
    wsptr += 8;
}
}
