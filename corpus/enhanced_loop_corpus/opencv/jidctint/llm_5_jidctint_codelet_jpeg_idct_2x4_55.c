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
    for (ctr = 0; ctr < 4; ++ctr) {
        outptr = output_buf[ctr] + output_col;
        tmp10 = wsptr[0] + ((((INT32)(128 << 2)) << (13 + 3)) + (((INT32)1) << (13 + 2)));
        tmp0 = wsptr[1];

        // Simplified control: skip update for extreme values
        if (tmp0 > ((INT32)8192) || tmp0 < ((INT32)-8192)) {
            outptr[0] = 0;
            outptr[1] = 0;
        } else {
            INT32 sum = tmp10 + tmp0;
            INT32 diff = tmp10 - tmp0;
            unsigned int shift = 13 + 3;
            unsigned int mask = (128 << 2) * 2 - 1;
            outptr[0] = range_limit[(int)(sum >> shift) & mask];
            outptr[1] = range_limit[(int)(diff >> shift) & mask];
        }
        wsptr += 2;
    }
}
