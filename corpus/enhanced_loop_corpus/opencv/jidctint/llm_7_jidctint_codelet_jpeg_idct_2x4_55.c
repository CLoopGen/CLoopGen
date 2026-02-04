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
    INT32 base_offset = ((((INT32)(128 << 2)) << (13 + 3)) + (((INT32)1) << (13 + 2)));
    INT32 *local_wsptr = wsptr; // Remove loop-carried dependency on wsptr by using local pointer
    for (ctr = 0; ctr < 4; ctr++) {
        outptr = output_buf[ctr] + output_col;
        tmp10 = local_wsptr[0] + base_offset;
        tmp0 = local_wsptr[1];

        // Eliminate repeated computation of shift and mask (common subexpression eliminated)
        const int shift = 13 + 3;
        const int mask = (128 << 2) * 2 - 1;

        outptr[0] = range_limit[(int)((tmp10 + tmp0) >> shift) & mask];
        outptr[1] = range_limit[(int)((tmp10 - tmp0) >> shift) & mask];

        local_wsptr += 2; // Use local pointer to remove WAR/WAW over wsptr
    }
    wsptr = local_wsptr; // Update global wsptr after loop (preserving semantics)
}
