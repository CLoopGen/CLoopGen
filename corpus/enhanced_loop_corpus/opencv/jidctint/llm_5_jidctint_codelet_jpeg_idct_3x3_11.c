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
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ++ctr) {
    // Simplified control flow with early exit condition based on input data
    outptr = output_buf[ctr] + output_col;

    // Precompute shift and bias constants for clarity and performance
    const INT32 offset = ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2))) << 13;
    tmp0 = (INT32)wsptr[0] + offset;
    tmp2 = (INT32)wsptr[2];

    // Skip computation if input is zero (control dependency introduced)
    if (wsptr[0] == 0 && wsptr[1] == 0 && wsptr[2] == 0) {
        outptr[0] = range_limit[128]; // Default mid-point value
        outptr[1] = range_limit[128];
        outptr[2] = range_limit[128];
        wsptr += 3;
        continue;
    }

    tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;
    tmp12 = (INT32)wsptr[1];
    tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp10 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)(tmp2 >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    wsptr += 3;
}
}
