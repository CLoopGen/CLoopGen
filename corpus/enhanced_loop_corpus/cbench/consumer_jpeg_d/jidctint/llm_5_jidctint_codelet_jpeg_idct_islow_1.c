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



void loop(){
for (ctr = 0; ctr < 8; ++ctr) {
    outptr = output_buf[ctr] + output_col;

    int non_zero_count = 0;
    non_zero_count += (wsptr[1] != 0);
    non_zero_count += (wsptr[2] != 0);
    non_zero_count += (wsptr[3] != 0);
    non_zero_count += (wsptr[4] != 0);
    non_zero_count += (wsptr[5] != 0);
    non_zero_count += (wsptr[6] != 0);
    non_zero_count += (wsptr[7] != 0);

    if (non_zero_count == 0) {
        JSAMPLE dcval = range_limit[(wsptr[0] + (1 << (2 + 3 - 1))) >> (2 + 3) & (255 * 4 + 3)];
        for (int i = 0; i < 8; ++i) {
            outptr[i] = dcval;
        }
        wsptr += 8;
        continue;
    }

    z2 = wsptr[2]; z3 = wsptr[6];
    z1 = (z2 + z3) * 4433;
    tmp2 = z1 - z3 * 15137;
    tmp3 = z1 + z2 * 6270;
    tmp0 = (wsptr[0] + wsptr[4]) << 13;
    tmp1 = (wsptr[0] - wsptr[4]) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + z2;
    tmp12 = tmp1 - z2;

    tmp0 = wsptr[7]; tmp1 = wsptr[5]; tmp2 = wsptr[3]; tmp3 = wsptr[1];
    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = (z3 + z4) * 9633;

    tmp0 *= 2446; tmp1 *= 16819; tmp2 *= 25172; tmp3 *= 12299;
    z1 *= -7373; z2 *= -20995; z3 *= -16069; z4 *= -3196;

    z3 += z5; z4 += z5;
    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    INT32 sum_shift = (13 + 2 + 3);
    INT32 round = 1 << (sum_shift - 1);
    INT32 mask = 255 * 4 + 3;

    outptr[0] = range_limit[(tmp10 + tmp3 + round) >> sum_shift & mask];
    outptr[7] = range_limit[(tmp10 - tmp3 + round) >> sum_shift & mask];
    outptr[1] = range_limit[(tmp11 + tmp2 + round) >> sum_shift & mask];
    outptr[6] = range_limit[(tmp11 - tmp2 + round) >> sum_shift & mask];
    outptr[2] = range_limit[(tmp12 + tmp1 + round) >> sum_shift & mask];
    outptr[5] = range_limit[(tmp12 - tmp1 + round) >> sum_shift & mask];
    outptr[3] = range_limit[(tmp13 + tmp0 + round) >> sum_shift & mask];
    outptr[4] = range_limit[(tmp13 - tmp0 + round) >> sum_shift & mask];

    wsptr += 8;
}
}
