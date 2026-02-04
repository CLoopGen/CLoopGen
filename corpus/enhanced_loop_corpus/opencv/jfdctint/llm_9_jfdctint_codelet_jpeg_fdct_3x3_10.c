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
for (ctr = 0; ctr < 2; ctr++) {
    for (int block = 0; block < 2; block++) {
        elemptr = sample_data[ctr + block] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[2]));
        tmp1 = ((int)(elemptr[1]));
        dataptr[0] = (DCTELEM)((tmp0 + tmp1 - 3 * 128) << (2 + 2));
        dataptr[2] = (DCTELEM)(((((tmp0 - tmp1 - tmp1) * (((INT32)((0.707106781) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 10)) >> 11);
        tmp2 = ((int)(elemptr[0])) - ((int)(elemptr[2]));
        dataptr[1] = (DCTELEM)(((((tmp2) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 10)) >> 11);
        dataptr += 8;
    }
}
}
