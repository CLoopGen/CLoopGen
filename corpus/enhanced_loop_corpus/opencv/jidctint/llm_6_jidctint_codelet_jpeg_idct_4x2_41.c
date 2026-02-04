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
extern INT32 *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 2; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp0 = wsptr[0] + ((((INT32)(128 << 2)) << 3) + (((INT32)1) << 2));
    tmp2 = wsptr[2];
    tmp10 = (tmp0 + tmp2) << 13;
    tmp12 = (tmp0 - tmp2) << 13;
    z2 = wsptr[1];
    z3 = wsptr[3];
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp0 = z1 + ((z2) * (((INT32)6270)));
    tmp2 = z1 - ((z3) * (((INT32)15137)));

    // Introduce WAW dependency by reusing tmp0/tmp2 after computation
    // Also introduce artificial RAW dependency on previous iteration via static carry
    static INT32 carry_tmp10 = 0, carry_tmp12 = 0;
    tmp10 += carry_tmp10;
    tmp12 += carry_tmp12;

    outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp10 - tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp12 + tmp2) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp12 - tmp2) >> (13 + 3)) & ((128 << 2) * 2 - 1)];

    // Update carry for next iteration (loop-carried dependency introduced)
    carry_tmp10 = (wsptr[0] - wsptr[2]) << 11;
    carry_tmp12 = (wsptr[0] + wsptr[2]) << 11;

    wsptr += 4;
}
}
