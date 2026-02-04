#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp12;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG local_tmp0, local_tmp2, local_tmp10, local_tmp12;
    for (ctr = 0; ctr < 3; ctr++) {
        outptr = output_buf[ctr] + output_col;
        local_tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
        local_tmp0 = ((JLONG)((unsigned long)(local_tmp0) << (13)));
        local_tmp2 = (JLONG)wsptr[2];
        local_tmp12 = ((local_tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
        local_tmp10 = local_tmp0 + local_tmp12;
        local_tmp2 = local_tmp0 - local_tmp12 - local_tmp12;
        local_tmp12 = (JLONG)wsptr[1];
        local_tmp0 = ((local_tmp12) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
        outptr[0] = range_limit[(int)((local_tmp10 + local_tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)((local_tmp10 - local_tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)((local_tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        wsptr += 3;
    }
}
