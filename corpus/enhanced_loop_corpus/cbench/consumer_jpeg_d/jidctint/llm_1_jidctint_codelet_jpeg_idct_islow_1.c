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
    if ((wsptr[1] | wsptr[2] | wsptr[3] | wsptr[4] | wsptr[5] | wsptr[6] | wsptr[7]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        int j = 0;
        for (; j < 8; ++j) {
            outptr[j] = dcval;
        }
        wsptr += 8;
        continue;
    }

    INT32 local_wsptr[8];
    for (int k = 0; k < 8; ++k) {
        local_wsptr[k] = (INT32)wsptr[k];
    }

    z2 = local_wsptr[2];
    z3 = local_wsptr[6];
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp2 = z1 + ((z3) * (-((INT32)15137)));
    tmp3 = z1 + ((z2) * (((INT32)6270)));
    tmp0 = (local_wsptr[0] + local_wsptr[4]) << 13;
    tmp1 = (local_wsptr[0] - local_wsptr[4]) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + z2;
    tmp12 = tmp1 - z2;

    tmp0 = local_wsptr[7];
    tmp1 = local_wsptr[5];
    tmp2 = local_wsptr[3];
    tmp3 = local_wsptr[1];

    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = ((z3 + z4) * (((INT32)9633)));

    tmp0 *= ((INT32)2446);
    tmp1 *= ((INT32)16819);
    tmp2 *= ((INT32)25172);
    tmp3 *= ((INT32)12299);

    z1 *= (-((INT32)7373));
    z2 *= (-((INT32)20995));
    z3 *= (-((INT32)16069));
    z4 *= (-((INT32)3196));

    z3 += z5;
    z4 += z5;

    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    INT32 results[8];
    results[0] = tmp10 + tmp3;
    results[7] = tmp10 - tmp3;
    results[1] = tmp11 + tmp2;
    results[6] = tmp11 - tmp2;
    results[2] = tmp12 + tmp1;
    results[5] = tmp12 - tmp1;
    results[3] = tmp13 + tmp0;
    results[4] = tmp13 - tmp0;

    int shift = 13 + 2 + 3;
    for (int idx = 0; idx < 8; ++idx) {
        outptr[idx] = range_limit[(int)((results[idx] + (((INT32)1) << (shift - 1))) >> shift) & (255 * 4 + 3)];
    }

    wsptr += 8;
}
}
