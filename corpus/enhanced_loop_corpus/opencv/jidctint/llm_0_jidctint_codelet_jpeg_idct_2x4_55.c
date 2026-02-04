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
extern INT32 tmp10;
extern INT32 *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (ctr = 0; ctr < 2; ctr++) {
            int idx = outer * 2 + ctr;
            outptr = output_buf[idx] + output_col;
            tmp10 = wsptr[0] + ((((INT32)(128 << 2)) << (13 + 3)) + (((INT32)1) << (13 + 2)));
            tmp0 = wsptr[1];
            outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
            outptr[1] = range_limit[(int)((tmp10 - tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
            wsptr += 2;
        }
    }
}
