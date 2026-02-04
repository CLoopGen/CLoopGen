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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM workspace[24];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int outer = 0; outer < 2; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            if (ctr >= 11) goto exit_loop;

            elemptr = sample_data[ctr] + start_col;

            tmp0 = ((int)elemptr[0]) + ((int)elemptr[10]);
            tmp1 = ((int)elemptr[1]) + ((int)elemptr[9]);
            tmp2 = ((int)elemptr[2]) + ((int)elemptr[8]);
            tmp3 = ((int)elemptr[3]) + ((int)elemptr[7]);
            tmp4 = ((int)elemptr[4]) + ((int)elemptr[6]);
            tmp5 = ((int)elemptr[5]);

            tmp10 = ((int)elemptr[0]) - ((int)elemptr[10]);
            tmp11 = ((int)elemptr[1]) - ((int)elemptr[9]);
            tmp12 = ((int)elemptr[2]) - ((int)elemptr[8]);
            tmp13 = ((int)elemptr[3]) - ((int)elemptr[7]);
            tmp14 = ((int)elemptr[4]) - ((int)elemptr[6]);

            dataptr[0] = (DCTELEM)((tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 - 11 * 128) << 1);
            tmp5 <<= 1;
            tmp0 -= tmp5;
            tmp1 -= tmp5;
            tmp2 -= tmp5;
            tmp3 -= tmp5;
            tmp4 -= tmp5;

            z1 = (tmp0 + tmp3) * 11135 + (tmp2 + tmp4) * 1649;
            z2 = (tmp1 - tmp3) * 7585;
            z3 = (tmp0 - tmp1) * 9747;

            dataptr[2] = (DCTELEM)((z1 + z2 - tmp3 * 8345 - tmp4 * 11390 + 2048) >> 12);
            dataptr[4] = (DCTELEM)((z2 + z3 + tmp1 * 510 - tmp2 * 11135 + tmp4 * 4815 + 2048) >> 12);
            dataptr[6] = (DCTELEM)((z1 + z3 - tmp0 * 13287 - tmp2 * 6462 + 2048) >> 12);

            tmp1 = (tmp10 + tmp11) * 10542;
            tmp2 = (tmp10 + tmp12) * 8764;
            tmp3 = (tmp10 + tmp13) * 6267;
            tmp0 = tmp1 + tmp2 + tmp3 - tmp10 * 14118 + tmp14 * 3266;

            tmp4 = (tmp11 + tmp12) * (-6267);
            tmp5 = (tmp11 + tmp13) * (-11467);
            tmp1 += tmp4 + tmp5 + tmp11 * 10458 - tmp14 * 8764;

            tmp10 = (tmp12 + tmp13) * 3266;
            tmp2 += tmp4 + tmp10 - tmp12 * 16299 + tmp14 * 11467;
            tmp3 += tmp5 + tmp10 + tmp13 * 10698 - tmp14 * 10542;

            dataptr[1] = (DCTELEM)((tmp0 + 2048) >> 12);
            dataptr[3] = (DCTELEM)((tmp1 + 2048) >> 12);
            dataptr[5] = (DCTELEM)((tmp2 + 2048) >> 12);
            dataptr[7] = (DCTELEM)((tmp3 + 2048) >> 12);

            ctr++;
            if (ctr != 8) {
                if (ctr == 11) goto exit_loop;
                dataptr += 8;
            } else {
                dataptr = workspace;
            }
        }
    }
exit_loop:;
}
