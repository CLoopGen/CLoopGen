#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef int DCTELEM;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z5;
extern DCTELEM z10;
extern DCTELEM z11;
extern DCTELEM z12;
extern DCTELEM z13;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 16; ctr += 2) {
        outptr = output_buf[ctr % 8] + output_col;
        DCTELEM sum = wsptr[0] + wsptr[1] + wsptr[2] + wsptr[3] +
                      wsptr[4] + wsptr[5] + wsptr[6] + wsptr[7];
        DCTELEM diff = wsptr[0] - wsptr[7];
        if (sum == 0) {
            JSAMPLE dcval = range_limit[((int)(wsptr[0] >> (2 + 3))) & (255 * 4 + 3)];
            for (int i = 0; i < 8; ++i) {
                outptr[i] = dcval;
            }
            wsptr += 8;
            continue;
        }
        tmp0 = ((DCTELEM)wsptr[0] + (DCTELEM)wsptr[4]) + ((DCTELEM)wsptr[2] + (DCTELEM)wsptr[6]);
        tmp3 = ((DCTELEM)wsptr[0] - (DCTELEM)wsptr[4]) - (((DCTELEM)((((DCTELEM)wsptr[2] - (DCTELEM)wsptr[6]) * 362) >> 8)) - ((DCTELEM)wsptr[2] + (DCTELEM)wsptr[6]));
        tmp1 = ((DCTELEM)wsptr[0] - (DCTELEM)wsptr[4]) + (((DCTELEM)((((DCTELEM)wsptr[2] - (DCTELEM)wsptr[6]) * 362) >> 8)) - ((DCTELEM)wsptr[2] + (DCTELEM)wsptr[6]));
        tmp2 = ((DCTELEM)wsptr[0] - (DCTELEM)wsptr[4]) - (((DCTELEM)((((DCTELEM)wsptr[2] - (DCTELEM)wsptr[6]) * 362) >> 8)) - ((DCTELEM)wsptr[2] + (DCTELEM)wsptr[6]));

        z13 = (DCTELEM)wsptr[5] + (DCTELEM)wsptr[3];
        z11 = (DCTELEM)wsptr[1] + (DCTELEM)wsptr[7];
        tmp7 = z11 + z13;
        z10 = (DCTELEM)wsptr[5] - (DCTELEM)wsptr[3];
        z12 = (DCTELEM)wsptr[1] - (DCTELEM)wsptr[7];
        z5 = ((DCTELEM)((z10 + z12) * 473) >> 8);
        tmp10 = ((DCTELEM)(z12 * 277) >> 8) - z5;
        tmp12 = ((DCTELEM)(z10 * (-669)) >> 8) + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = ((DCTELEM)((z11 - z13) * 362) >> 8) - tmp6;
        tmp4 = tmp10 + tmp5;

        outptr[0] = range_limit[((int)((tmp0 + tmp7) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[7] = range_limit[((int)((tmp0 - tmp7) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[1] = range_limit[((int)((tmp1 + tmp6) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[6] = range_limit[((int)((tmp1 - tmp6) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[2] = range_limit[((int)((tmp2 + tmp5) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[5] = range_limit[((int)((tmp2 - tmp5) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[4] = range_limit[((int)((tmp3 + tmp4) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[3] = range_limit[((int)((tmp3 - tmp4) >> (2 + 3))) & (255 * 4 + 3)];

        wsptr += 8;

        if (ctr + 1 < 16) {
            outptr = output_buf[(ctr + 1) % 8] + output_col;
            JSAMPLE dcval = range_limit[((int)((wsptr[0]) >> (2 + 3))) & (255 * 4 + 3)];
            for (int i = 0; i < 8; ++i) {
                outptr[i] = dcval;
            }
            wsptr += 8;
        }
    }
}
