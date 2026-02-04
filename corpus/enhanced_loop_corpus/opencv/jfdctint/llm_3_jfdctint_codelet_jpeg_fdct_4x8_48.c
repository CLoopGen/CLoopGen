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
JSAMPROW row_ptrs[8];
for (ctr = 0; ctr < 8; ++ctr) {
    row_ptrs[ctr] = sample_data[ctr] + start_col;
}
for (ctr = 0; ctr < 8; ++ctr) {
    JSAMPROW elemptr_local = row_ptrs[ctr];
    tmp0 = ((int)(elemptr_local[0])) + ((int)(elemptr_local[3]));
    tmp1 = ((int)(elemptr_local[1])) + ((int)(elemptr_local[2]));
    tmp10 = ((int)(elemptr_local[0])) - ((int)(elemptr_local[3]));
    tmp11 = ((int)(elemptr_local[1])) - ((int)(elemptr_local[2]));
    (dataptr + ctr * 8)[0] = (DCTELEM)((tmp0 + tmp1 - 4 * 128) << (2 + 1));
    (dataptr + ctr * 8)[2] = (DCTELEM)((tmp0 - tmp1) << (2 + 1));
    tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
    tmp0 += ((INT32)1) << (13 - 2 - 2);
    (dataptr + ctr * 8)[1] = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 - 2 - 1));
    (dataptr + ctr * 8)[3] = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 - 2 - 1));
}
}
