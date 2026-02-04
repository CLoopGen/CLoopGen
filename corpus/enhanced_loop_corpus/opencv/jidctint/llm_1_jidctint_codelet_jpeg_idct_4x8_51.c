#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 8; ctr++) {
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            outptr = output_buf[ctr] + output_col;
            tmp0 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
            tmp2 = (INT32)wsptr[2];
            tmp10 = (tmp0 + tmp2) << 13;
            tmp12 = (tmp0 - tmp2) << 13;
            z2 = (INT32)wsptr[1];
            z3 = (INT32)wsptr[3];
            z1 = ((z2 + z3) * (((INT32)4433)));
            tmp0 = z1 + ((z2) * (((INT32)6270)));
            tmp2 = z1 - ((z3) * (((INT32)15137)));
            outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
            outptr[3] = range_limit[(int)((tmp10 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
            outptr[1] = range_limit[(int)((tmp12 + tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
            outptr[2] = range_limit[(int)((tmp12 - tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
            wsptr += 4;
        }
    }
}
