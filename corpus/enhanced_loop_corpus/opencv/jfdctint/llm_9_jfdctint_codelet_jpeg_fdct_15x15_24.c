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
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM workspace[56];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int block = 0; block < 2; block++) {
    for (int row = 0; row < 8; row++) {
        elemptr = sample_data[ctr] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[14]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[13]));
        tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[12]));
        tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[11]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[10]));
        tmp5 = ((int)(elemptr[5])) + ((int)(elemptr[9]));
        tmp6 = ((int)(elemptr[6])) + ((int)(elemptr[8]));
        tmp7 = ((int)(elemptr[7]));

        z1 = tmp0 + tmp4 + tmp5;
        z2 = tmp1 + tmp3 + tmp6;
        z3 = tmp2 + tmp7;
        dataptr[0] = (DCTELEM)(z1 + z2 + z3 - 15 * 128);

        z3 <<= 1;
        dataptr[6] = (DCTELEM)((((z1 - z3) * 9367 - (z2 - z3) * 3578) + 4096) >> 13);

        tmp2 += (tmp1 + tmp4) / 2 - (tmp7 << 1);
        z1 = (tmp3 - tmp2) * 12537 - (tmp6 - tmp2) * 18315;
        z2 = (tmp5 - tmp2) * 6537 - (tmp0 - tmp2) * 748;
        z3 = (tmp0 - tmp3) * 11334 + (tmp6 - tmp5) * 7748 + (tmp1 - tmp4) * 6474;

        dataptr[2] = (DCTELEM)(((z1 + z3) + 4096) >> 13);
        dataptr[4] = (DCTELEM)(((z2 + z3) + 4096) >> 13);

        tmp2 = (tmp10 = ((int)(elemptr[0]) - (int)(elemptr[14]))) -
                    ((int)(elemptr[2]) - (int)(elemptr[12])) -
                    ((int)(elemptr[3]) - (int)(elemptr[11])) +
                    ((int)(elemptr[5]) - (int)(elemptr[9])) +
                    ((int)(elemptr[6]) - (int)(elemptr[8]));
        tmp2 *= 10030;

        tmp1 = (tmp10 - ((int)(elemptr[4]) - (int)(elemptr[10])) - ((int)(elemptr[5]) - (int)(elemptr[9]))) * 11008 +
               (tmp11 = ((int)(elemptr[1]) - (int)(elemptr[13])) - ((int)(elemptr[3]) - (int)(elemptr[11])) - ((int)(elemptr[6]) - (int)(elemptr[8]))) * 6799;

        tmp12 = ((int)(elemptr[2]) - (int)(elemptr[12])) * 10030;

        tmp4 = (tmp10 - ((int)(elemptr[6]) - (int)(elemptr[8]))) * 11515 +
               (tmp11 + ((int)(elemptr[4]) - (int)(elemptr[10]))) * 11008 +
               (((int)(elemptr[3]) - (int)(elemptr[11])) + ((int)(elemptr[5]) - (int)(elemptr[9]))) * 4712;

        tmp0 = ((int)(elemptr[3]) - (int)(elemptr[11])) * 3896 -
               ((int)(elemptr[4]) - (int)(elemptr[10])) * 4207 +
               ((int)(elemptr[6]) - (int)(elemptr[8])) * 13919 + tmp4 + tmp12;

        tmp3 = tmp10 * (-2911) - tmp11 * 17807 - ((int)(elemptr[5]) - (int)(elemptr[9])) * 7119 + tmp4 - tmp12;

        dataptr[1] = (DCTELEM)(((tmp0) + 4096) >> 13);
        dataptr[3] = (DCTELEM)(((tmp1) + 4096) >> 13);
        dataptr[5] = (DCTELEM)(((tmp2) + 4096) >> 13);
        dataptr[7] = (DCTELEM)(((tmp3) + 4096) >> 13);

        ctr++;
        dataptr += 8;
    }
    dataptr = workspace;
}
}
