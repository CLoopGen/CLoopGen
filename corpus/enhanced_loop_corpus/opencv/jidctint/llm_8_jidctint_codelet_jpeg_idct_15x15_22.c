#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

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
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 4; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z1 = ((JLONG)((unsigned long)(z1) << (13)));
    z1 += ((JLONG)1) << (13 - 1 - 1);
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
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
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    z3 = ((z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
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
    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 1));
    wsptr[8 * 14] = (int)((tmp20 - tmp10) >> (13 - 1));
    wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 1));
    wsptr[8 * 13] = (int)((tmp21 - tmp11) >> (13 - 1));
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 1));
    wsptr[8 * 12] = (int)((tmp22 - tmp12) >> (13 - 1));
    wsptr[8 * 3] = (int)((tmp23 + tmp13) >> (13 - 1));
    wsptr[8 * 11] = (int)((tmp23 - tmp13) >> (13 - 1));
    wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 1));
    wsptr[8 * 10] = (int)((tmp24 - tmp14) >> (13 - 1));
    wsptr[8 * 5] = (int)((tmp25 + tmp15) >> (13 - 1));
    wsptr[8 * 9] = (int)((tmp25 - tmp15) >> (13 - 1));
    wsptr[8 * 6] = (int)((tmp26 + tmp16) >> (13 - 1));
    wsptr[8 * 8] = (int)((tmp26 - tmp16) >> (13 - 1));
    wsptr[8 * 7] = (int)((tmp27) >> (13 - 1));
}
}
