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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with reordered computation and modified dependencies (WAR hazard introduced)
for (ctr = 0; ctr < 6; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    // Rearranged to reuse tmp0, tmp1, tmp2 earlier and delay reassignment — creates WAR-like pattern
    INT32 e0 = (int)(elemptr[0]), e1 = (int)(elemptr[1]), e2 = (int)(elemptr[2]);
    INT32 e3 = (int)(elemptr[3]), e4 = (int)(elemptr[4]), e5 = (int)(elemptr[5]);

    tmp0 = e0 + e5;
    tmp11 = e1 + e4;
    tmp2 = e2 + e3;
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;

    // Delayed use of subtraction differences — reduces RAW pressure
    INT32 d0 = e0 - e5;
    INT32 d1 = e1 - e4;
    INT32 d2 = e2 - e3;

    // Use intermediate values directly instead of reassigning tmp0,tmp1,tmp2 immediately
    dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 6 * 128) << 2);
    dataptr[2] = (DCTELEM)(((((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 11)) >> 11);
    dataptr[4] = (DCTELEM)(((((tmp10 - tmp11 - tmp11) * (((INT32)((0.707106781) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 11)) >> 11);

    tmp10 = (((((d0 + d2) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 11)) >> 11);
    dataptr[1] = (DCTELEM)(tmp10 + ((d0 + d1) << 2));
    dataptr[3] = (DCTELEM)((d0 - d1 - d2) << 2);
    dataptr[5] = (DCTELEM)(tmp10 + ((d2 - d1) << 2));

    // Final assignment to original tmp variables only after all uses — breaks WAW
    tmp0 = d0;
    tmp1 = d1;
    tmp2 = d2;

    dataptr += 8;
}
}
