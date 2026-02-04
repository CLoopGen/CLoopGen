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
extern JLONG tmp25;
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
    for (int outer = 0; outer < 2; outer++) {
        for (ctr = 0; ctr < 11; ctr++) {
            outptr = output_buf[ctr] + output_col;
            tmp10 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
            tmp10 = ((JLONG)((unsigned long)(tmp10) << (13)));
            z1 = (JLONG)wsptr[2];
            z2 = (JLONG)wsptr[4];
            z3 = (JLONG)wsptr[6];
            tmp20 = ((z2 - z3) * (((JLONG)((2.5466401319999998) * (((JLONG)1) << 13) + 0.5))));
            tmp23 = ((z2 - z1) * (((JLONG)((0.43081504500000001) * (((JLONG)1) << 13) + 0.5))));
            z4 = z1 + z3;
            tmp24 = ((z4) * (-((JLONG)((1.155664402) * (((JLONG)1) << 13) + 0.5))));
            z4 -= z2;
            tmp25 = tmp10 + ((z4) * (((JLONG)((1.3569279759999999) * (((JLONG)1) << 13) + 0.5))));
            tmp21 = tmp20 + tmp23 + tmp25 - ((z2) * (((JLONG)((1.821790775) * (((JLONG)1) << 13) + 0.5))));
            tmp20 += tmp25 + ((z3) * (((JLONG)((2.1158250870000002) * (((JLONG)1) << 13) + 0.5))));
            tmp23 += tmp25 - ((z1) * (((JLONG)((1.5135984769999999) * (((JLONG)1) << 13) + 0.5))));
            tmp24 += tmp25;
            tmp22 = tmp24 - ((z3) * (((JLONG)((0.78874911999999997) * (((JLONG)1) << 13) + 0.5))));
            tmp24 += ((z2) * (((JLONG)((1.9444135220000001) * (((JLONG)1) << 13) + 0.5)))) - ((z1) * (((JLONG)((1.3909757300000001) * (((JLONG)1) << 13) + 0.5))));
            tmp25 = tmp10 - ((z4) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));
            z1 = (JLONG)wsptr[1];
            z2 = (JLONG)wsptr[3];
            z3 = (JLONG)wsptr[5];
            z4 = (JLONG)wsptr[7];
            tmp11 = z1 + z2;
            tmp14 = ((tmp11 + z3 + z4) * (((JLONG)((0.39843000299999998) * (((JLONG)1) << 13) + 0.5))));
            tmp11 = ((tmp11) * (((JLONG)((0.88798390199999999) * (((JLONG)1) << 13) + 0.5))));
            tmp12 = ((z1 + z3) * (((JLONG)((0.67036129499999997) * (((JLONG)1) << 13) + 0.5))));
            tmp13 = tmp14 + ((z1 + z4) * (((JLONG)((0.36615157399999998) * (((JLONG)1) << 13) + 0.5))));
            tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((0.92310786600000005) * (((JLONG)1) << 13) + 0.5))));
            z1 = tmp14 - ((z2 + z3) * (((JLONG)((1.163011579) * (((JLONG)1) << 13) + 0.5))));
            tmp11 += z1 + ((z2) * (((JLONG)((2.0732765880000001) * (((JLONG)1) << 13) + 0.5))));
            tmp12 += z1 - ((z3) * (((JLONG)((1.1921936230000001) * (((JLONG)1) << 13) + 0.5))));
            z1 = ((z2 + z4) * (-((JLONG)((1.7982489100000001) * (((JLONG)1) << 13) + 0.5))));
            tmp11 += z1;
            tmp13 += z1 + ((z4) * (((JLONG)((2.1024586319999998) * (((JLONG)1) << 13) + 0.5))));
            tmp14 += ((z2) * (-((JLONG)((1.4672213009999999) * (((JLONG)1) << 13) + 0.5)))) + ((z3) * (((JLONG)((1.001388905) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.6848439070000001) * (((JLONG)1) << 13) + 0.5))));
            outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[10] = range_limit[(int)((tmp20 - tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[9] = range_limit[(int)((tmp21 - tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[8] = range_limit[(int)((tmp22 - tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[7] = range_limit[(int)((tmp23 - tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[6] = range_limit[(int)((tmp24 - tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            outptr[5] = range_limit[(int)((tmp25) >> (13 + 1 + 3)) & (255 * 4 + 3)];
            wsptr += 8;
        }
    }
}
