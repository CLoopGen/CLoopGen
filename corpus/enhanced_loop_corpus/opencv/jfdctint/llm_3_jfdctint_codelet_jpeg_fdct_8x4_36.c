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
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (ctr = 0; ctr < 4; ctr++) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[indices[0]])) + ((int)(elemptr[indices[7]]));
        tmp1 = ((int)(elemptr[indices[1]])) + ((int)(elemptr[indices[6]]));
        tmp2 = ((int)(elemptr[indices[2]])) + ((int)(elemptr[indices[5]]));
        tmp3 = ((int)(elemptr[indices[3]])) + ((int)(elemptr[indices[4]]));
        tmp10 = tmp0 + tmp3;
        tmp12 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp13 = tmp1 - tmp2;
        tmp0 = ((int)(elemptr[indices[0]])) - ((int)(elemptr[indices[7]]));
        tmp1 = ((int)(elemptr[indices[1]])) - ((int)(elemptr[indices[6]]));
        tmp2 = ((int)(elemptr[indices[2]])) - ((int)(elemptr[indices[5]]));
        tmp3 = ((int)(elemptr[indices[3]])) - ((int)(elemptr[indices[4]]));
        dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 8 * 128) << (2 + 1));
        dataptr[4] = (DCTELEM)((tmp10 - tmp11) << (2 + 1));
        z1 = ((tmp12 + tmp13) * (((INT32)4433)));
        z1 += ((INT32)1) << (13 - 2 - 2);
        dataptr[2] = (DCTELEM)((z1 + ((tmp12) * (((INT32)6270)))) >> (13 - 2 - 1));
        dataptr[6] = (DCTELEM)((z1 - ((tmp13) * (((INT32)15137)))) >> (13 - 2 - 1));
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp1 + tmp3;
        z1 = ((tmp12 + tmp13) * (((INT32)9633)));
        z1 += ((INT32)1) << (13 - 2 - 2);
        tmp12 = ((tmp12) * (-((INT32)3196)));
        tmp13 = ((tmp13) * (-((INT32)16069)));
        tmp12 += z1;
        tmp13 += z1;
        z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
        tmp0 = ((tmp0) * (((INT32)12299)));
        tmp3 = ((tmp3) * (((INT32)2446)));
        tmp0 += z1 + tmp12;
        tmp3 += z1 + tmp13;
        z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
        tmp1 = ((tmp1) * (((INT32)25172)));
        tmp2 = ((tmp2) * (((INT32)16819)));
        tmp1 += z1 + tmp13;
        tmp2 += z1 + tmp12;
        dataptr[1] = (DCTELEM)((tmp0) >> (13 - 2 - 1));
        dataptr[3] = (DCTELEM)((tmp1) >> (13 - 2 - 1));
        dataptr[5] = (DCTELEM)((tmp2) >> (13 - 2 - 1));
        dataptr[7] = (DCTELEM)((tmp3) >> (13 - 2 - 1));
        dataptr += 8;
    }
}
