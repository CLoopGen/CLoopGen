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
    // Variant 1: Consecutive Memory Access with Prefetched Pointers
    // Instead of recalculating outptr each iteration, we precompute base pointers and access them consecutively.
    JSAMPROW base_ptrs[4];
    for (int i = 0; i < 4; i++) {
        base_ptrs[i] = output_buf[i] + output_col;
    }
    INT32 *local_wsptr = wsptr;
    for (ctr = 0; ctr < 4; ctr++) {
        outptr = base_ptrs[ctr];
        tmp10 = local_wsptr[0] + ((((INT32)(128 << 2)) << (13 + 3)) + (((INT32)1) << (13 + 2)));
        tmp0 = local_wsptr[1];
        outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp10 - tmp0) >> (13 + 3)) & ((128 << 2) * 2 - 1)];
        local_wsptr += 2;
    }
    wsptr = local_wsptr; // Update global wsptr after loop
}
