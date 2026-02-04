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
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
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
for (ctr = 0; ctr < 10; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z3 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    z3 = ((JLONG)((unsigned long)(z3) << (13)));
    z4 = (JLONG)wsptr[4];
    z1 = ((z4) * (((JLONG)((1.1441228059999999) * (((JLONG)1) << 13) + 0.5))));
    z2 = ((z4) * (((JLONG)((0.437016024) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = z3 + z1;
    tmp11 = z3 - z2;
    tmp22 = z3 - ((JLONG)((unsigned long)(z1 - z2) << (1)));
    z2 = (JLONG)wsptr[2];
    z3 = (JLONG)wsptr[6];
    z1 = ((z2 + z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = z1 + ((z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = z1 - ((z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp12;
    tmp24 = tmp10 - tmp12;
    tmp21 = tmp11 + tmp13;
    tmp23 = tmp11 - tmp13;
    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    z3 = ((JLONG)((unsigned long)(z3) << (13)));
    z4 = (JLONG)wsptr[7];
    tmp11 = z2 + z4;
    tmp13 = z2 - z4;
    tmp12 = ((tmp13) * (((JLONG)((0.30901699399999999) * (((JLONG)1) << 13) + 0.5))));
    z2 = ((tmp11) * (((JLONG)((0.95105651599999996) * (((JLONG)1) << 13) + 0.5))));
    z4 = z3 + tmp12;
    tmp10 = ((z1) * (((JLONG)((1.3968022470000001) * (((JLONG)1) << 13) + 0.5)))) + z2 + z4;
    tmp14 = ((z1) * (((JLONG)((0.22123174200000001) * (((JLONG)1) << 13) + 0.5)))) - z2 + z4;
    z2 = ((tmp11) * (((JLONG)((0.58778525199999998) * (((JLONG)1) << 13) + 0.5))));
    z4 = z3 - tmp12 - ((JLONG)((unsigned long)(tmp13) << (13 - 1)));
    tmp12 = ((JLONG)((unsigned long)(z1 - tmp13) << (13))) - z3;
    tmp11 = ((z1) * (((JLONG)((1.2600735110000001) * (((JLONG)1) << 13) + 0.5)))) - z2 - z4;
    tmp13 = ((z1) * (((JLONG)((0.64203952200000003) * (((JLONG)1) << 13) + 0.5)))) - z2 + z4;

    if ((tmp20 + tmp10) > (tmp20 - tmp10)) {
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[9] = range_limit[(int)((tmp20 - tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    } else {
        outptr[0] = range_limit[0];
        outptr[9] = range_limit[255];
    }

    if ((tmp21 + tmp11) > (tmp21 - tmp11)) {
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[8] = range_limit[(int)((tmp21 - tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    } else {
        outptr[1] = range_limit[0];
        outptr[8] = range_limit[255];
    }

    if ((tmp22 + tmp12) % 2 == 0) {
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)((tmp22 - tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    } else {
        outptr[2] = range_limit[64];
        outptr[7] = range_limit[192];
    }

    outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[6] = range_limit[(int)((tmp23 - tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[5] = range_limit[(int)((tmp24 - tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    wsptr += 8;
}
}
