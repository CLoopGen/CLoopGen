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
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ctr = 0; ctr < 4; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int)(elemptr[0]));
    tmp1 = ((int)(elemptr[1]));
    dataptr[0] = (DCTELEM)(tmp0 + tmp1 - 2 * 128);
    dataptr[1] = (DCTELEM)(tmp0 - tmp1);
    dataptr += 8;
}

}
