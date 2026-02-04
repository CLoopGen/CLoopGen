#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 4; ctr++) {
        outptr = output_buf[ctr] + output_col;
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];

        if ((wsptr[1] | wsptr[2] | wsptr[3]) == 0) {
            for (int k = 0; k < 8; k++) {
                outptr[k] = dcval;
            }
            wsptr += 8;
        } else {
            tmp0 = ((INT32)wsptr[0] + (INT32)wsptr[4]) << 13;
            tmp1 = ((INT32)wsptr[0] - (INT32)wsptr[4]) << 13;
            z2 = (INT32)wsptr[2];
            z3 = (INT32)wsptr[6];
            z1 = (z2 + z3) * (INT32)4433;
            tmp2 = z1 - (z3 * (INT32)15137);
            tmp3 = z1 + (z2 * (INT32)6270);
            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;

            z1 = (INT32)(wsptr[7] + wsptr[1]) * (-(INT32)7373);
            z2 = (INT32)(wsptr[5] + wsptr[3]) * (-(INT32)20995);
            z3 = (INT32)(wsptr[7] + wsptr[3]) * (-(INT32)16069);
            z4 = (INT32)(wsptr[5] + wsptr[1]) * (-(INT32)3196);
            z5 = (z3 + z4) * (INT32)9633;
            z3 += z5;
            z4 += z5;

            tmp0 = (INT32)wsptr[7] * (INT32)2446 + z1 + z3;
            tmp1 = (INT32)wsptr[5] * (INT32)16819 + z2 + z4;
            tmp2 = (INT32)wsptr[3] * (INT32)25172 + z2 + z3;
            tmp3 = (INT32)wsptr[1] * (INT32)12299 + z1 + z4;

            INT32 round = 1 << (18 - 1);
            INT32 mask = 1023;

            outptr[0] = range_limit[(int)((tmp10 + tmp3 + round) >> 18) & mask];
            outptr[7] = range_limit[(int)((tmp10 - tmp3 + round) >> 18) & mask];
            outptr[1] = range_limit[(int)((tmp11 + tmp2 + round) >> 18) & mask];
            outptr[6] = range_limit[(int)((tmp11 - tmp2 + round) >> 18) & mask];

            wsptr += 8;
        }

        outptr = output_buf[ctr + 4] + output_col;
        if ((wsptr[1] | wsptr[2] | wsptr[3]) == 0) {
            for (int k = 0; k < 8; k++) {
                outptr[k] = dcval;
            }
            wsptr += 8;
        } else {
            tmp0 = ((INT32)wsptr[0] + (INT32)wsptr[4]) << 13;
            tmp1 = ((INT32)wsptr[0] - (INT32)wsptr[4]) << 13;
            z2 = (INT32)wsptr[2];
            z3 = (INT32)wsptr[6];
            z1 = (z2 + z3) * (INT32)4433;
            tmp2 = z1 - (z3 * (INT32)15137);
            tmp3 = z1 + (z2 * (INT32)6270);
            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;

            z1 = (INT32)(wsptr[7] + wsptr[1]) * (-(INT32)7373);
            z2 = (INT32)(wsptr[5] + wsptr[3]) * (-(INT32)20995);
            z3 = (INT32)(wsptr[7] + wsptr[3]) * (-(INT32)16069);
            z4 = (INT32)(wsptr[5] + wsptr[1]) * (-(INT32)3196);
            z5 = (z3 + z4) * (INT32)9633;
            z3 += z5;
            z4 += z5;

            tmp0 = (INT32)wsptr[7] * (INT32)2446 + z1 + z3;
            tmp1 = (INT32)wsptr[5] * (INT32)16819 + z2 + z4;
            tmp2 = (INT32)wsptr[3] * (INT32)25172 + z2 + z3;
            tmp3 = (INT32)wsptr[1] * (INT32)12299 + z1 + z4;

            INT32 round = 1 << (18 - 1);
            INT32 mask = 1023;

            outptr[2] = range_limit[(int)((tmp12 + tmp1 + round) >> 18) & mask];
            outptr[5] = range_limit[(int)((tmp12 - tmp1 + round) >> 18) & mask];
            outptr[3] = range_limit[(int)((tmp13 + tmp0 + round) >> 18) & mask];
            outptr[4] = range_limit[(int)((tmp13 - tmp0 + round) >> 18) & mask];

            wsptr += 8;
        }
    }
}
