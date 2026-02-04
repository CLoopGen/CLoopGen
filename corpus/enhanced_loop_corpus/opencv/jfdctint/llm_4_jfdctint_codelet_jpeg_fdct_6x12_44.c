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
extern DCTELEM workspace[32];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[5]));
        tmp11 = ((int)(elemptr[1])) + ((int)(elemptr[4]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[3]));
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;
        tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[5]));
        tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[4]));
        tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[3]));
        dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 6 * 128) << 2);
        dataptr[2] = (DCTELEM)(((((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[4] = (DCTELEM)(((((tmp10 - tmp11 - tmp11) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        tmp10 = (((((tmp0 + tmp2) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[1] = (DCTELEM)(tmp10 + ((tmp0 + tmp1) << 2));
        dataptr[3] = (DCTELEM)((tmp0 - tmp1 - tmp2) << 2);
        dataptr[5] = (DCTELEM)(tmp10 + ((tmp2 - tmp1) << 2));

        ctr++;
        if (ctr == 8) {
            dataptr = workspace;
        } else if (ctr < 12) {
            dataptr += 8;
        } else {
            break;
        }
    }
}
