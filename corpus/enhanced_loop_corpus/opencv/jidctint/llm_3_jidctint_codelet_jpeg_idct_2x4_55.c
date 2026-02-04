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
    // Variant 2: Strided Memory Access with Offset Indexing
    // Replace repeated pointer arithmetic with strided indexing into wsptr and output_buf using fixed stride.
    INT32 *base_wsptr = wsptr;
    for (ctr = 0; ctr < 8; ctr += 2) { // Process two elements per original iteration, unrolled stride
        outptr = output_buf[ctr >> 1] + output_col; // Map 0,2,4,6 -> 0,1,2,3
        tmp10 = base_wsptr[ctr + 0] + ((((INT32)(128 << 2)) << (13 + 3)) + (((INT32)1) << (13 + 2)));
        tmp0 = base_wsptr[ctr + 1];
        outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp10 - tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
    }
    wsptr += 8; // Update wsptr by total consumed elements (4 iterations × 2)
}
