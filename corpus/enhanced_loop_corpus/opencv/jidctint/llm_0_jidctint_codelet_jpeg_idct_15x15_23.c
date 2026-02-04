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
extern JLONG tmp15;
extern JLONG tmp16;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG tmp27;
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
for (int outer = 0; outer < 3; outer++) {
    for (ctr = 0; ctr < 5; ctr++) {
        int idx = outer * 5 + ctr;
        outptr = output_buf[idx] + output_col;
        z1 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
        z1 = ((JLONG)((unsigned long)(z1) << (13)));
        z2 = (JLONG)wsptr[2];
        z3 = (JLONG)wsptr[4];
        z4 = (JLONG)wsptr[6];
        tmp10 = ((z4) * (((JLONG)((0.437016024) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((JLONG)((1.1441228059999999) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = z1 - tmp10;
        tmp13 = z1 + tmp11;
        z1 -= ((JLONG)((unsigned long)(tmp11 - tmp10) << (1)));
        z4 = z2 - z3;
        z3 += z2;
        tmp10 = ((z3) * (((JLONG)((1.33762899) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((JLONG)((0.045680613000000002) * (((JLONG)1) << 13) + 0.5))));
        z2 = ((z2) * (((JLONG)((1.4397739460000001) * (((JLONG)1) << 13) + 0.5))));
        tmp20 = tmp13 + tmp10 + tmp11;
        tmp23 = tmp12 - tmp10 + tmp11 + z2;
        tmp10 = ((z3) * (((JLONG)((0.54705957400000005) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((JLONG)((0.39923400399999998) * (((JLONG)1) << 13) + 0.5))));
        tmp25 = tmp13 - tmp10 - tmp11;
        tmp26 = tmp12 + tmp10 - tmp11 - z2;
        tmp10 = ((z3) * (((JLONG)((0.790569415) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((z4) * (((JLONG)((0.35355339099999999) * (((JLONG)1) << 13) + 0.5))));
        tmp21 = tmp12 + tmp10 + tmp11;
        tmp24 = tmp13 - tmp10 + tmp11;
        tmp11 += tmp11;
        tmp22 = z1 + tmp11;
        tmp27 = z1 - tmp11 - tmp11;
        z1 = (JLONG)wsptr[1];
        z2 = (JLONG)wsptr[3];
        z4 = (JLONG)wsptr[5];
        z3 = ((z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
        z4 = (JLONG)wsptr[7];
        tmp13 = z2 - z4;
        tmp15 = ((z1 + tmp13) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = tmp15 + ((z1) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
        tmp14 = tmp15 - ((tmp13) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = ((z2) * (-((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
        tmp15 = ((z2) * (-((JLONG)((1.344997024) * (((JLONG)1) << 13) + 0.5))));
        z2 = z1 - z4;
        tmp12 = z3 + ((z2) * (((JLONG)((1.4064663529999999) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = tmp12 + ((z4) * (((JLONG)((2.4574318439999998) * (((JLONG)1) << 13) + 0.5)))) - tmp15;
        tmp16 = tmp12 - ((z1) * (((JLONG)((1.11243482) * (((JLONG)1) << 13) + 0.5)))) + tmp13;
        tmp12 = ((z2) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5)))) - z3;
        z2 = ((z1 + z4) * (((JLONG)((0.575212477) * (((JLONG)1) << 13) + 0.5))));
        tmp13 += z2 + ((z1) * (((JLONG)((0.47575301399999997) * (((JLONG)1) << 13) + 0.5)))) - z3;
        tmp15 += z2 - ((z4) * (((JLONG)((0.86924400999999996) * (((JLONG)1) << 13) + 0.5)))) + z3;
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[14] = range_limit[(int)((tmp20 - tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[13] = range_limit[(int)((tmp21 - tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[12] = range_limit[(int)((tmp22 - tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[11] = range_limit[(int)((tmp23 - tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[10] = range_limit[(int)((tmp24 - tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)((tmp25 + tmp15) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[9] = range_limit[(int)((tmp25 - tmp15) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)((tmp26 + tmp16) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[8] = range_limit[(int)((tmp26 - tmp16) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)((tmp27) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        wsptr += 8;
    }
}
}
