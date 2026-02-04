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
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[5] == 0 && wsptr[6] == 0 && wsptr[7] == 0) {
        JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[0]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
        wsptr += 8;
        continue;
    }
    tmp0 = ((JLONG)((unsigned long)((JLONG)wsptr[0]) << (13 + 1)));
    tmp2 = (((JLONG)wsptr[2]) * (((JLONG)15137))) + (((JLONG)wsptr[6]) * (-((JLONG)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;

    z1 = (JLONG)wsptr[7];
    z2 = (JLONG)wsptr[5];
    z3 = (JLONG)wsptr[3];
    z4 = (JLONG)wsptr[1];

    JLONG sum_z = z1 + z2 + z3 + z4;
    JLONG diff_z = z1 - z4 + z2 - z3;

    tmp0 = ((sum_z) * (-((JLONG)1730))) + ((diff_z) * (((JLONG)8697))) + ((z2) * (((JLONG)13623))) + ((z3) * (-((JLONG)19532)));
    tmp2 = ((sum_z) * (-((JLONG)4176))) + ((diff_z) * (((JLONG)20995))) + ((z2) * (((JLONG)26069))) + ((z3) * (((JLONG)2474)));

    outptr[0] = range_limit[(int)(((tmp10 + tmp2) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)(((tmp10 - tmp2) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)(((tmp12 + tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)(((tmp12 - tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 1) - 1))) >> (13 + 1 + 3 + 1)) & (255 * 4 + 3)];

    tmp0 = ((JLONG)wsptr[4]) * (((JLONG)10000));
    tmp2 = ((JLONG)wsptr[0]) * (((JLONG)5000));
    outptr[0] = range_limit[(int)(((tmp2 + (((JLONG)1) << (13))) >> 14) + outptr[0]) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)(((tmp0 + (((JLONG)1) << (13))) >> 14) + outptr[3]) & (255 * 4 + 3)];

    wsptr += 8;
}

}
