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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern DCTELEM workspace[8];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 4; outer++) {
    for (int inner = 0; inner < 2; inner++) {
        int idx = outer * 2 + inner;
        elemptr = sample_data[idx] + start_col;

        tmp0 = ((int)(elemptr[0]) + (int)(elemptr[8]));
        tmp1 = ((int)(elemptr[1]) + (int)(elemptr[7]));
        tmp2 = ((int)(elemptr[2]) + (int)(elemptr[6]));
        tmp3 = ((int)(elemptr[3]) + (int)(elemptr[5]));
        tmp4 = ((int)(elemptr[4]));

        tmp10 = ((int)(elemptr[0]) - (int)(elemptr[8]));
        tmp11 = ((int)(elemptr[1]) - (int)(elemptr[7]));
        tmp12 = ((int)(elemptr[2]) - (int)(elemptr[6]));
        tmp13 = ((int)(elemptr[3]) - (int)(elemptr[5]));

        z1 = tmp0 + tmp2 + tmp3;
        z2 = tmp1 + tmp4;

        dataptr[0] = (DCTELEM)((z1 + z2 - 9 * 128) << 1);
        dataptr[6] = (DCTELEM)((((z1 - z2 - z2) * 5898) + 2048) >> 12);

        z1 = (tmp0 - tmp2) * 10937;
        z2 = (tmp1 - tmp4 - tmp4) * 5898;

        dataptr[2] = (DCTELEM)((((tmp2 - tmp3) * 8933) + z1 + z2 + 2048) >> 12);
        dataptr[4] = (DCTELEM)((((tmp3 - tmp0) * 2027) + z1 - z2 + 2048) >> 12);

        dataptr[3] = (DCTELEM)((((tmp10 - tmp12 - tmp13) * 10084) + 2048) >> 12);

        tmp11 = tmp11 * 10084;
        tmp0 = (tmp10 + tmp12) * 7477;
        tmp1 = (tmp10 + tmp13) * 3984;

        dataptr[1] = (DCTELEM)((tmp11 + tmp0 + tmp1 + 2048) >> 12);
        tmp2 = (tmp12 - tmp13) * 11474;
        dataptr[5] = (DCTELEM)((tmp0 - tmp11 - tmp2 + 2048) >> 12);
        dataptr[7] = (DCTELEM)((tmp1 - tmp11 + tmp2 + 2048) >> 12);

        if (inner == 1)
            dataptr = workspace;
        else
            dataptr += 8;
    }
}
}
