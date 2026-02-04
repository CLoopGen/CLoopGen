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
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
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
for (ctr = 0; ctr < 13; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z1 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    z1 = ((JLONG)((unsigned long)(z1) << (13)));
    z2 = (JLONG)wsptr[2];
    z3 = (JLONG)wsptr[4];
    z4 = (JLONG)wsptr[6];
    tmp10 = z3 + z4;
    tmp11 = z3 - z4;
    tmp12 = ((tmp10) * (((JLONG)((1.155388986) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.096834933999999998) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp20 = ((z2) * (((JLONG)((1.373119086) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp22 = ((z2) * (((JLONG)((0.50148704099999997) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;
    tmp12 = ((tmp10) * (((JLONG)((0.31645013100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.48691473899999999) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp21 = ((z2) * (((JLONG)((1.0585540520000001) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;
    tmp25 = ((z2) * (-((JLONG)((1.25222392) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp12 = ((tmp10) * (((JLONG)((0.435816023) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.93730306399999996) * (((JLONG)1) << 13) + 0.5)))) - z1;
    tmp23 = ((z2) * (-((JLONG)((0.17046460799999999) * (((JLONG)1) << 13) + 0.5)))) - tmp12 - tmp13;
    tmp24 = ((z2) * (-((JLONG)((0.80336486900000004) * (((JLONG)1) << 13) + 0.5)))) + tmp12 - tmp13;
    tmp26 = ((tmp11 - z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5)))) + z1;
    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    z4 = (JLONG)wsptr[7];
    tmp11 = ((z1 + z2) * (((JLONG)((1.3223126510000001) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = ((z1 + z3) * (((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp15 = z1 + z4;
    tmp13 = ((tmp15) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((2.0200822999999999) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2 + z3) * (-((JLONG)((0.33844345799999997) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += tmp14 + ((z2) * (((JLONG)((0.83722356399999998) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp14 - ((z3) * (((JLONG)((1.5721160270000001) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2 + z4) * (-((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += tmp14;
    tmp13 += tmp14 + ((z4) * (((JLONG)((2.205608352) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z3 + z4) * (-((JLONG)((0.65721781300000004) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp14;
    tmp13 += tmp14;
    tmp15 = ((tmp15) * (((JLONG)((0.33844345799999997) * (((JLONG)1) << 13) + 0.5))));
    tmp14 += ((z1) * (((JLONG)((0.31877435500000001) * (((JLONG)1) << 13) + 0.5)))) - ((z2) * (((JLONG)((0.466105296) * (((JLONG)1) << 13) + 0.5))));
    z1 = ((z3 - z2) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));
    tmp14 += z1;
    tmp15 += z1 + ((z3) * (((JLONG)((0.38451559499999999) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.7423458110000001) * (((JLONG)1) << 13) + 0.5))));
    
    if (ctr % 2 == 0) {
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[12] = range_limit[(int)((tmp20 - tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[11] = range_limit[(int)((tmp21 - tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[10] = range_limit[(int)((tmp22 - tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    } else {
        outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[9] = range_limit[(int)((tmp23 - tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[8] = range_limit[(int)((tmp24 - tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)((tmp25 + tmp15) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)((tmp25 - tmp15) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    }
    outptr[6] = range_limit[(int)((tmp26) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    wsptr += 8;
}
}
