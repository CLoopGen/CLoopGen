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
for (ctr = 0; ctr < 16; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
    z1 = (JLONG)wsptr[4];
    tmp1 = ((z1) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
    tmp2 = ((z1) * (((JLONG)4433)));
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp12 = tmp0 + tmp2;
    tmp13 = tmp0 - tmp2;
    z1 = (JLONG)wsptr[2];
    z2 = (JLONG)wsptr[6];
    z3 = z1 - z2;
    z4 = ((z3) * (((JLONG)((0.275899379) * (((JLONG)1) << 13) + 0.5))));
    z3 = ((z3) * (((JLONG)((1.3870398450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = z3 + ((z2) * (((JLONG)20995)));
    tmp1 = z4 + ((z1) * (((JLONG)7373)));
    tmp2 = z3 - ((z1) * (((JLONG)((0.60134488699999999) * (((JLONG)1) << 13) + 0.5))));
    tmp3 = z4 - ((z2) * (((JLONG)((0.50979557900000005) * (((JLONG)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp0;
    tmp27 = tmp10 - tmp0;
    tmp21 = tmp12 + tmp1;
    tmp26 = tmp12 - tmp1;
    tmp22 = tmp13 + tmp2;
    tmp25 = tmp13 - tmp2;
    tmp23 = tmp11 + tmp3;
    tmp24 = tmp11 - tmp3;
    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    z4 = (JLONG)wsptr[7];
    tmp11 = z1 + z3;
    tmp1 = ((z1 + z2) * (((JLONG)((1.3533180010000001) * (((JLONG)1) << 13) + 0.5))));
    tmp2 = ((tmp11) * (((JLONG)((1.247225013) * (((JLONG)1) << 13) + 0.5))));
    tmp3 = ((z1 + z4) * (((JLONG)((1.0932018670000001) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = ((z1 - z4) * (((JLONG)((0.89716758600000002) * (((JLONG)1) << 13) + 0.5))));
    tmp11 = ((tmp11) * (((JLONG)((0.66665565800000004) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = ((z1 - z2) * (((JLONG)((0.410524528) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = tmp1 + tmp2 + tmp3 - ((z1) * (((JLONG)((2.2863411440000001) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = tmp10 + tmp11 + tmp12 - ((z1) * (((JLONG)((1.835730603) * (((JLONG)1) << 13) + 0.5))));
    z1 = ((z2 + z3) * (((JLONG)((0.13861716900000001) * (((JLONG)1) << 13) + 0.5))));
    tmp1 += z1 + ((z2) * (((JLONG)((0.071888073999999996) * (((JLONG)1) << 13) + 0.5))));
    tmp2 += z1 - ((z3) * (((JLONG)((1.125726048) * (((JLONG)1) << 13) + 0.5))));
    z1 = ((z3 - z2) * (((JLONG)((1.407403738) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += z1 - ((z3) * (((JLONG)((0.76636728200000004) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += z1 + ((z2) * (((JLONG)((1.971951411) * (((JLONG)1) << 13) + 0.5))));
    z2 += z4;
    z1 = ((z2) * (-((JLONG)((0.66665565800000004) * (((JLONG)1) << 13) + 0.5))));
    tmp1 += z1;
    tmp3 += z1 + ((z4) * (((JLONG)((1.0653889620000001) * (((JLONG)1) << 13) + 0.5))));
    z2 = ((z2) * (-((JLONG)((1.247225013) * (((JLONG)1) << 13) + 0.5))));
    tmp10 += z2 + ((z4) * (((JLONG)((3.141271809) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += z2;
    z2 = ((z3 + z4) * (-((JLONG)((1.3533180010000001) * (((JLONG)1) << 13) + 0.5))));
    tmp2 += z2;
    tmp3 += z2;
    z2 = ((z4 - z3) * (((JLONG)((0.410524528) * (((JLONG)1) << 13) + 0.5))));
    tmp10 += z2;
    tmp11 += z2;

    // Introduce temporary variables to break WAW and WAR dependencies
    JLONG t20 = tmp20, t0 = tmp0, t21 = tmp21, t1 = tmp1, t22 = tmp22, t2 = tmp2, t23 = tmp23, t3 = tmp3;
    JLONG t24 = tmp24, t10 = tmp10, t25 = tmp25, t11 = tmp11, t26 = tmp26, t12 = tmp26, t27 = tmp27, t13 = tmp13;

    outptr[0] = range_limit[(int)((t20 + t0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[15] = range_limit[(int)((t20 - t0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)((t21 + t1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[14] = range_limit[(int)((t21 - t1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)((t22 + t2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[13] = range_limit[(int)((t22 - t2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)((t23 + t3) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[12] = range_limit[(int)((t23 - t3) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[4] = range_limit[(int)((t24 + t10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[11] = range_limit[(int)((t24 - t10) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[5] = range_limit[(int)((t25 + t11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[10] = range_limit[(int)((t25 - t11) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[6] = range_limit[(int)((t26 + t12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[9] = range_limit[(int)((t26 - t12) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[7] = range_limit[(int)((t27 + t13) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[8] = range_limit[(int)((t27 - t13) >> (13 + 1 + 3)) & (255 * 4 + 3)];

    wsptr += 8;
}
}
