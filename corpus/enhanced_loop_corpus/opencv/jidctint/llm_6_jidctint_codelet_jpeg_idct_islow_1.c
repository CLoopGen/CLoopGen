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
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
        outptr[4] = dcval;
        outptr[5] = dcval;
        outptr[6] = dcval;
        outptr[7] = dcval;
        wsptr += 8;
        continue;
    }
    JLONG ws0 = (JLONG)wsptr[0];
    JLONG ws1 = (JLONG)wsptr[1];
    JLONG ws2 = (JLONG)wsptr[2];
    JLONG ws3 = (JLONG)wsptr[3];
    JLONG ws4 = (JLONG)wsptr[4];
    JLONG ws5 = (JLONG)wsptr[5];
    JLONG ws6 = (JLONG)wsptr[6];
    JLONG ws7 = (JLONG)wsptr[7];

    z2 = ws2;
    z3 = ws6;
    z1 = (z2 + z3) * ((JLONG)4433);
    tmp2 = z1 + (z3 * (-(JLONG)15137));
    tmp3 = z1 + (z2 * (JLONG)6270);
    tmp0 = (ws0 + ws4) << 13;
    tmp1 = (ws0 - ws4) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    z1 = ws7 + ws3;
    z2 = ws5 + ws2;
    z3 = ws7 + ws2;
    z4 = ws5 + ws3;
    z5 = (z3 + z4) * (JLONG)9633;

    JLONG t0 = ws7 * (JLONG)2446;
    JLONG t1 = ws5 * (JLONG)16819;
    JLONG t2 = ws2 * (JLONG)25172;
    JLONG t3 = ws3 * (JLONG)12299;

    z1 *= -(JLONG)7373;
    z2 *= -(JLONG)20995;
    z3 *= -(JLONG)16069;
    z4 *= -(JLONG)3196;

    z3 += z5;
    z4 += z5;

    tmp0 = t0 + z1 + z3;
    tmp1 = t1 + z2 + z4;
    tmp2 = t2 + z2 + z3;
    tmp3 = t3 + z1 + z4;

    JLONG offset = (1 << (13 + 1 + 3 - 1));
    JLONG shift = (13 + 1 + 3);
    JLONG mask = (255 * 4 + 3);

    outptr[0] = range_limit[(int)(((tmp10 + tmp3) + offset) >> shift) & mask];
    outptr[7] = range_limit[(int)(((tmp10 - tmp3) + offset) >> shift) & mask];
    outptr[1] = range_limit[(int)(((tmp11 + tmp2) + offset) >> shift) & mask];
    outptr[6] = range_limit[(int)(((tmp11 - tmp2) + offset) >> shift) & mask];
    outptr[2] = range_limit[(int)(((tmp12 + tmp1) + offset) >> shift) & mask];
    outptr[5] = range_limit[(int)(((tmp12 - tmp1) + offset) >> shift) & mask];
    outptr[3] = range_limit[(int)(((tmp13 + tmp0) + offset) >> shift) & mask];
    outptr[4] = range_limit[(int)(((tmp13 - tmp0) + offset) >> shift) & mask];

    wsptr += 8;
}
}
