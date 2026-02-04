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
int outer_ctr;
for (outer_ctr = 0; outer_ctr < 1; outer_ctr++) {
    for (ctr = 0; ctr < 3; ctr++) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[2]));
        tmp1 = ((int)(elemptr[1]));
        tmp2 = ((int)(elemptr[0])) - ((int)(elemptr[2]));
        dataptr[0] = (DCTELEM)((tmp0 + tmp1 - 3 * 128) << (2 + 2));
        dataptr[2] = (DCTELEM)(((((tmp0 - tmp1 - tmp1) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 2) - 1))) >> (13 - 2 - 2));
        dataptr[1] = (DCTELEM)(((((tmp2) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 2) - 1))) >> (13 - 2 - 2));
        dataptr += 8;
    }
}
}
