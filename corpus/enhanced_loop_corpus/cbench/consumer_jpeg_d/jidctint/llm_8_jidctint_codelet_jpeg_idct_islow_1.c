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
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    if ((wsptr[1] | wsptr[2] | wsptr[3] | wsptr[4]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
        wsptr += 4;
        continue;
    }
    tmp0 = ((INT32)wsptr[0] + (INT32)wsptr[3]) << 10;
    tmp1 = ((INT32)wsptr[0] - (INT32)wsptr[3]) << 10;
    tmp2 = ((INT32)wsptr[1]) * (((INT32)362));
    tmp3 = ((INT32)wsptr[2]) * (((INT32)317));
    z1 = ((INT32)1) << ((10 + 2 + 3) - 1);
    outptr[0] = range_limit[(int)(((tmp0 + tmp3 + z1) >> (10 + 2 + 3)) & (255 * 4 + 3))];
    outptr[3] = range_limit[(int)(((tmp0 - tmp3 + z1) >> (10 + 2 + 3)) & (255 * 4 + 3))];
    outptr[1] = range_limit[(int)(((tmp1 + tmp2 + z1) >> (10 + 2 + 3)) & (255 * 4 + 3))];
    outptr[2] = range_limit[(int)(((tmp1 - tmp2 + z1) >> (10 + 2 + 3)) & (255 * 4 + 3))];
    wsptr += 4;
}
}
