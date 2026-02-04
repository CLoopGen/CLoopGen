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
    // Remove some immediate data dependencies by precomputing scaling factors
    const INT32 offset = ((((INT32)(128 << 2)) << 3) + (((INT32)1) << 2));
    INT32 local_wsptr[4];
    for (int i = 0; i < 4; ++i) {
        local_wsptr[i] = wsptr[i]; // Break aliasing, remove repeated loads
    }

    tmp0 = local_wsptr[0] + offset;
    tmp2 = local_wsptr[2];
    tmp10 = (tmp0 + tmp2) << 13;
    tmp12 = (tmp0 - tmp2) << 13;
    z2 = local_wsptr[1];
    z3 = local_wsptr[3];
    z1 = (z2 + z3) * (INT32)4433L;
    // Eliminate loop-carried dependency by making all operations intra-iteration independent
    // No state is carried between iterations

    // Reorder operations to change execution flow without affecting result
    INT32 result0 = (tmp10 + (z1 + z2 * 6270)) >> 16;
    INT32 result3 = (tmp10 - (z1 + z2 * 6270)) >> 16;
    INT32 result1 = (tmp12 + (z1 - z3 * 15137)) >> 16;
    INT32 result2 = (tmp12 - (z1 - z3 * 15137)) >> 16;

    outptr[0] = range_limit[(int)result0 & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)result3 & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)result1 & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)result2 & ((128 << 2) * 2 - 1)];

    wsptr += 4;
}
}
