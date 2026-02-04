#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++) {
    outptr = output_buf[ctr] + output_col;
    if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[4] == 0 && wsptr[5] == 0 && wsptr[6] == 0 && wsptr[7] == 0) {
        JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[0]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
        for (int i = 0; i < 8; i++) {
            outptr[i] = dcval;
        }
        wsptr += 8;
        continue;
    }

    JLONG local_wsptr[8];
    for (int i = 0; i < 8; i++) {
        local_wsptr[i] = (JLONG)wsptr[i];
    }

    z2 = local_wsptr[2];
    z3 = local_wsptr[6];
    z1 = (z2 + z3) * (JLONG)4433;
    tmp2 = z1 + (z3 * -(JLONG)15137);
    tmp3 = z1 + (z2 * (JLONG)6270);
    tmp0 = (local_wsptr[0] + local_wsptr[4]) << 13;
    tmp1 = (local_wsptr[0] - local_wsptr[4]) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    tmp0 = local_wsptr[7];
    tmp1 = local_wsptr[5];
    tmp2 = local_wsptr[3];
    tmp3 = local_wsptr[1];
    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = (z3 + z4) * (JLONG)9633;

    tmp0 *= (JLONG)2446;
    tmp1 *= (JLONG)16819;
    tmp2 *= (JLONG)25172;
    tmp3 *= (JLONG)12299;
    z1 *= -(JLONG)7373;
    z2 *= -(JLONG)20995;
    z3 *= -(JLONG)16069;
    z4 *= -(JLONG)3196;

    z3 += z5;
    z4 += z5;

    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    JLONG result[8];
    JLONG offset = (1LL << (13 + 1 + 3 - 1));
    JLONG shift = (13 + 1 + 3);
    JLONG mask = (255 * 4 + 3);

    result[0] = (tmp10 + tmp3);
    result[7] = (tmp10 - tmp3);
    result[1] = (tmp11 + tmp2);
    result[6] = (tmp11 - tmp2);
    result[2] = (tmp12 + tmp1);
    result[5] = (tmp12 - tmp1);
    result[3] = (tmp13 + tmp0);
    result[4] = (tmp13 - tmp0);

    for (int i = 0; i < 8; i++) {
        outptr[i] = range_limit[(int)((result[i] + offset) >> shift) & mask];
    }

    wsptr += 8;
}
}
