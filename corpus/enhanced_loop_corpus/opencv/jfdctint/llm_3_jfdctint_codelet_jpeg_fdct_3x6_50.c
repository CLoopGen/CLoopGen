#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 6; ++ctr) {
    JSAMPROW row = sample_data[ctr];
    elemptr = row + start_col;
    const int e0 = (int)elemptr[0];
    const int e1 = (int)elemptr[1];
    const int e2 = (int)elemptr[2];
    tmp0 = e0 + e2;
    tmp1 = e1;
    tmp2 = e0 - e2;
    DCTELEM *const dst = dataptr + ctr * 8;
    dst[0] = (DCTELEM)((tmp0 + tmp1 - 3 * 128) << 3);
    dst[2] = (DCTELEM)((((tmp0 - 2 * tmp1) * (INT32)(0.707106781 * (1 << 13) + 0.5)) + (1 << 10)) >> 11);
    dst[1] = (DCTELEM)(((tmp2 * (INT32)(1.224744871 * (1 << 13) + 0.5)) + (1 << 10)) >> 11);
}
}
