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
INT32 delayed_wsptr_loads[9];
for (ctr = 0; ctr < 3; ctr++) {
    int base_idx = ctr * 3;
    delayed_wsptr_loads[base_idx]     = wsptr[0];
    delayed_wsptr_loads[base_idx + 1] = wsptr[1];
    delayed_wsptr_loads[base_idx + 2] = wsptr[2];
    wsptr += 3;
}
wsptr -= 9; // Restore pointer for semantic consistency in external context

for (ctr = 0; ctr < 3; ctr++) {
    outptr = output_buf[ctr] + output_col;
    int base_idx = ctr * 3;
    INT32 loaded0 = delayed_wsptr_loads[base_idx];
    INT32 loaded1 = delayed_wsptr_loads[base_idx + 1];
    INT32 loaded2 = delayed_wsptr_loads[base_idx + 2];

    INT32 tmp0 = (INT32)loaded0 + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    tmp0 <<= 13;
    INT32 tmp2 = loaded2;
    INT32 tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    INT32 tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;
    tmp12 = loaded1;
    tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp10 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
}
}
