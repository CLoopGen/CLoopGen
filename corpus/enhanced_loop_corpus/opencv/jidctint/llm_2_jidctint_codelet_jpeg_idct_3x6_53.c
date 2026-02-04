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



void loop() {
    for (ctr = 0; ctr < 6; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int offset = ctr * 3; // Strided access pattern: wsptr accessed with increasing stride
        tmp0 = (INT32)wsptr[offset] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        tmp0 <<= 13;
        tmp2 = (INT32)wsptr[offset + 2];
        tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp0 + tmp12;
        tmp2 = tmp0 - tmp12 - tmp12;
        tmp12 = (INT32)wsptr[offset + 1];
        tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp10 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }
}
