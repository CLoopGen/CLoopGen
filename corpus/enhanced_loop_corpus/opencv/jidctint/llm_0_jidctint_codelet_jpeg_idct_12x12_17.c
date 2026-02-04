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
    for (ctr = 0; ctr < 12; ctr++) {
        outptr = output_buf[ctr] + output_col;
        z3 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
        z3 = ((JLONG)((unsigned long)(z3) << (13)));
        z4 = (JLONG)wsptr[4];
        z4 = ((z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = z3 + z4;
        tmp11 = z3 - z4;
        z1 = (JLONG)wsptr[2];
        z4 = ((z1) * (((JLONG)((1.3660254039999999) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((JLONG)((unsigned long)(z1) << (13)));
        z2 = (JLONG)wsptr[6];
        z2 = ((JLONG)((unsigned long)(z2) << (13)));
        tmp12 = z1 - z2;
        tmp21 = z3 + tmp12;
        tmp24 = z3 - tmp12;
        tmp12 = z4 + z2;
        tmp20 = tmp10 + tmp12;
        tmp25 = tmp10 - tmp12;
        tmp12 = z4 - z1 - z2;
        tmp22 = tmp11 + tmp12;
        tmp23 = tmp11 - tmp12;
        z1 = (JLONG)wsptr[1];
        z2 = (JLONG)wsptr[3];
        z3 = (JLONG)wsptr[5];
        z4 = (JLONG)wsptr[7];
        tmp11 = ((z2) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
        tmp14 = ((z2) * (-((JLONG)4433)));
        tmp10 = z1 + z3;
        tmp15 = ((tmp10 + z4) * (((JLONG)((0.86091866900000003) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = tmp15 + ((tmp10) * (((JLONG)((0.26105238400000003) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = tmp12 + tmp11 + ((z1) * (((JLONG)((0.28014371599999999) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = ((z3 + z4) * (-((JLONG)((1.04551058) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += tmp13 + tmp14 - ((z3) * (((JLONG)((1.478575242) * (((JLONG)1) << 13) + 0.5))));
        tmp13 += tmp15 - tmp11 + ((z4) * (((JLONG)((1.5867066809999999) * (((JLONG)1) << 13) + 0.5))));
        tmp15 += tmp14 - ((z1) * (((JLONG)((0.67632675799999997) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.982889723) * (((JLONG)1) << 13) + 0.5))));
        z1 -= z4;
        z2 -= z3;
        z3 = ((z1 + z2) * (((JLONG)4433)));
        tmp11 = z3 + ((z1) * (((JLONG)6270)));
        tmp14 = z3 - ((z2) * (((JLONG)15137)));
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[11] = range_limit[(int)((tmp20 - tmp10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[10] = range_limit[(int)((tmp21 - tmp11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[9] = range_limit[(int)((tmp22 - tmp12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)((tmp23 + tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[8] = range_limit[(int)((tmp23 - tmp13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)((tmp24 + tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)((tmp24 - tmp14) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)((tmp25 + tmp15) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)((tmp25 - tmp15) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        wsptr += 8;
        
        // Additional inner loop unrolling simulation: split computation into two parts
        for (int extra = 0; extra < 1; extra++) {
            // Dummy operation to simulate deeper nesting without functional change
            tmp10 = (tmp10 + tmp11) >> 1;
            tmp20 = (tmp20 + tmp21) >> 1;
        }
    }
}
