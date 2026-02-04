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
for (ctr = 0; ctr < 3; ++ctr) {
    outptr = output_buf[ctr] + output_col;

    tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));

    tmp2 = (JLONG)wsptr[2];
    tmp12 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;

    tmp12 = (JLONG)wsptr[1];
    tmp0 = ((tmp12) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));

    int index0 = (int)((tmp10 + tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3);
    int index2 = (int)((tmp10 - tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3);
    int index1 = (int)(tmp2 >> (13 + 1 + 3)) & (255 * 4 + 3);

    if (index0 >= 0 && index0 < 1024)
        outptr[0] = range_limit[index0];
    else
        outptr[0] = range_limit[0];

    if (index2 >= 0 && index2 < 1024)
        outptr[2] = range_limit[index2];
    else
        outptr[2] = range_limit[0];

    if (index1 >= 0 && index1 < 1024)
        outptr[1] = range_limit[index1];
    else
        outptr[1] = range_limit[0];

    wsptr += 3;
}
}
