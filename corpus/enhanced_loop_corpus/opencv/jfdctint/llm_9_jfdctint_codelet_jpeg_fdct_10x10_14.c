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
extern INT32 tmp14;
extern DCTELEM workspace[16];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
        int idx = i * 2 + j;
        if (idx >= 8) continue;

        elemptr = sample_data[idx] + start_col;
        tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[9]));
        tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[8]));
        tmp12 = ((int)(elemptr[2])) + ((int)(elemptr[7]));
        tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[6]));
        tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[5]));
        tmp10 = tmp0 + tmp4;
        tmp13 = tmp0 - tmp4;
        tmp11 = tmp1 + tmp3;
        tmp14 = tmp1 - tmp3;

        dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 - 10 * 128) << 1);
        tmp12 += tmp12;
        dataptr[4] = (DCTELEM)(((((tmp10 - tmp12) * 9370) - ((tmp11 - tmp12) * 3578)) + 4096) >> 12);

        tmp10 = (tmp13 + tmp14) * 6809;
        dataptr[2] = (DCTELEM)(((tmp10 + (tmp13 * 4207)) + 4096) >> 12);
        dataptr[6] = (DCTELEM)(((tmp10 - (tmp14 * 17828)) + 4096) >> 12);

        tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[9]));
        tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[8]));
        tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[7]));
        tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[6]));
        tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[5]));

        tmp10 = tmp0 + tmp4;
        tmp11 = tmp1 - tmp3;
        dataptr[5] = (DCTELEM)((tmp10 - tmp11 - tmp2) << 1);

        dataptr[1] = (DCTELEM)((((tmp0 * 11434) + (tmp1 * 10315) + (tmp2 << 13) + (tmp3 * 5260) + (tmp4 * 1812)) + 4096) >> 12);

        tmp12 = (tmp0 - tmp4) * 7790 - (tmp1 + tmp3) * 4814;
        tmp13 = (tmp10 + tmp11) * 2530 + (tmp11 << 12) - (tmp2 << 13);
        dataptr[3] = (DCTELEM)(((tmp12 + tmp13) + 4096) >> 12);
        dataptr[7] = (DCTELEM)(((tmp12 - tmp13) + 4096) >> 12);

        dataptr += 8;
    }
    if (i == 3) {
        dataptr = workspace;
        for (int j = 0; j < 2; j++) {
            int idx = 8 + j;
            if (idx >= 10) break;

            elemptr = sample_data[idx] + start_col;
            tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[9]));
            tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[8]));
            tmp12 = ((int)(elemptr[2])) + ((int)(elemptr[7]));
            tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[6]));
            tmp4 = ((int)(elemptr[4])) + ((int)(elemptr[5]));
            tmp10 = tmp0 + tmp4;
            tmp13 = tmp0 - tmp4;
            tmp11 = tmp1 + tmp3;
            tmp14 = tmp1 - tmp3;

            dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 - 1280) << 1);
            tmp12 += tmp12;
            dataptr[4] = (DCTELEM)(((((tmp10 - tmp12) * 9370) - ((tmp11 - tmp12) * 3578)) + 4096) >> 12);

            tmp10 = (tmp13 + tmp14) * 6809;
            dataptr[2] = (DCTELEM)(((tmp10 + (tmp13 * 4207)) + 4096) >> 12);
            dataptr[6] = (DCTELEM)(((tmp10 - (tmp14 * 17828)) + 4096) >> 12);

            tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[9]));
            tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[8]));
            tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[7]));
            tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[6]));
            tmp4 = ((int)(elemptr[4])) - ((int)(elemptr[5]));

            tmp10 = tmp0 + tmp4;
            tmp11 = tmp1 - tmp3;
            dataptr[5] = (DCTELEM)((tmp10 - tmp11 - tmp2) << 1);

            dataptr[1] = (DCTELEM)((((tmp0 * 11434) + (tmp1 * 10315) + (tmp2 << 13) + (tmp3 * 5260) + (tmp4 * 1812)) + 4096) >> 12);

            tmp12 = (tmp0 - tmp4) * 7790 - (tmp1 + tmp3) * 4814;
            tmp13 = (tmp10 + tmp11) * 2530 + (tmp11 << 12) - (tmp2 << 13);
            dataptr[3] = (DCTELEM)(((tmp12 + tmp13) + 4096) >> 12);
            dataptr[7] = (DCTELEM)(((tmp12 - tmp13) + 4096) >> 12);

            dataptr += 8;
        }
        break;
    }
}
}
