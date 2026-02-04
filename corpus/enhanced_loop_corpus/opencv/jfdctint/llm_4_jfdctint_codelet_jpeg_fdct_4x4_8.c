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
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 3, 1, 2};
    for (ctr = 0; ctr < 4; ctr++) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[indices[0]])) + ((int)(elemptr[indices[1]]));
        tmp1 = ((int)(elemptr[indices[2]])) + ((int)(elemptr[indices[3]]));
        tmp10 = ((int)(elemptr[indices[0]])) - ((int)(elemptr[indices[1]]));
        tmp11 = ((int)(elemptr[indices[2]])) - ((int)(elemptr[indices[3]]));
        dataptr[0] = (DCTELEM)((tmp0 + tmp1 - 4 * 128) << (2 + 2));
        dataptr[2] = (DCTELEM)((tmp0 - tmp1) << (2 + 2));
        tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
        tmp0 += ((INT32)1) << (13 - 2 - 3);
        dataptr[1] = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 - 2 - 2));
        dataptr[3] = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 - 2 - 2));
        dataptr += 8;
    }
}
