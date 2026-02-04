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
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp10 = wsptr[0] + ((((INT32)(128 << 2)) << (13 + 3)) + (((INT32)1) << (13 + 2)));
    tmp0 = wsptr[1];
    INT32 sum = tmp10 + tmp0;
    INT32 diff = tmp10 - tmp0;
    INT32 shift_val = (13 + 3);
    INT32 mask = (128 << 2) * 2 - 1;
    outptr[0] = range_limit[(int)(sum >> shift_val) & mask];
    outptr[1] = range_limit[(int)(diff >> shift_val) & mask];
    wsptr += 2;

    // Additional computational work to increase arithmetic intensity
    sum += diff;
    sum = (sum > 0) ? (sum << 1) : (-sum);
    outptr[2] = range_limit[(int)(sum >> shift_val) & mask];
    outptr[3] = range_limit[(int)((sum * 3) >> shift_val) & mask];
}
}
