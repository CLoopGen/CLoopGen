#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 tmp27;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Break some RAW dependencies by reordering independent computations
    // and introducing temporary variables to eliminate WAW hazards

    INT32 t_z1_early = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    INT32 t_z2_early = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    INT32 t_z3_early = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    INT32 t_z4_early = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

    INT32 t_z1b = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    INT32 t_z2b = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    INT32 t_z4b = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    INT32 t_z5b = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    z1 = t_z1_early;
    z1 <<= 13;
    z1 += ((INT32)1) << (13 - 2 - 1);
    z2 = t_z2_early;
    z3 = t_z3_early;
    z4 = t_z4_early;

    tmp10 = ((z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
    tmp11 = ((z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    tmp12 = z1 - tmp10;
    tmp13 = z1 + tmp11;
    z1 -= (tmp11 - tmp10) << 1;
    z4 = z2 - z3;
    z3 += z2;

    tmp10 = ((z3) * (((INT32)((1.33762899) * (((INT32)1) << 13) + 0.5))));
    tmp11 = ((z4) * (((INT32)((0.045680613000000002) * (((INT32)1) << 13) + 0.5))));
    z2 = ((z2) * (((INT32)((1.4397739460000001) * (((INT32)1) << 13) + 0.5))));

    tmp20 = tmp13 + tmp10 + tmp11;
    tmp23 = tmp12 - tmp10 + tmp11 + z2;

    tmp10 = ((z3) * (((INT32)((0.54705957400000005) * (((INT32)1) << 13) + 0.5))));
    tmp11 = ((z4) * (((INT32)((0.39923400399999998) * (((INT32)1) << 13) + 0.5))));
    tmp25 = tmp13 - tmp10 - tmp11;
    tmp26 = tmp12 + tmp10 - tmp11 - z2;

    tmp10 = ((z3) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
    tmp11 = ((z4) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
    tmp21 = tmp12 + tmp10 + tmp11;
    tmp24 = tmp13 - tmp10 + tmp11;
    tmp11 += tmp11;
    tmp22 = z1 + tmp11;
    tmp27 = z1 - tmp11 - tmp11;

    // Use pre-fetched values from earlier to reduce RAW stalls
    z1 = t_z1b;
    z2 = t_z2b;
    z4 = t_z4b;
    z3 = ((z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    z4 = t_z5b;

    tmp13 = z2 - z4;
    tmp15 = ((z1 + tmp13) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp11 = tmp15 + ((z1) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    tmp14 = tmp15 - ((tmp13) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = ((z2) * (-((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp15 = ((z2) * (-((INT32)((1.344997024) * (((INT32)1) << 13) + 0.5))));
    z2 = z1 - z4;
    tmp12 = z3 + ((z2) * (((INT32)((1.4064663529999999) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp12 + ((z4) * (((INT32)((2.4574318439999998) * (((INT32)1) << 13) + 0.5)))) - tmp15;
    tmp16 = tmp12 - ((z1) * (((INT32)((1.11243482) * (((INT32)1) << 13) + 0.5)))) + tmp13;
    tmp12 = ((z2) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5)))) - z3;
    z2 = ((z1 + z4) * (((INT32)((0.575212477) * (((INT32)1) << 13) + 0.5))));
    tmp13 += z2 + ((z1) * (((INT32)((0.47575301399999997) * (((INT32)1) << 13) + 0.5)))) - z3;
    tmp15 += z2 - ((z4) * (((INT32)((0.86924400999999996) * (((INT32)1) << 13) + 0.5)))) + z3;

    // Store results with shuffled order but same semantics
    wsptr[8 * 7] = (int)((tmp27) >> (13 - 2));
    wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[8 * 14] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[8 * 13] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[8 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
    wsptr[8 * 12] = (int)((tmp22 - tmp12) >> (13 - 2));
    wsptr[8 * 3] = (int)((tmp23 + tmp13) >> (13 - 2));
    wsptr[8 * 11] = (int)((tmp23 - tmp13) >> (13 - 2));
    wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 2));
    wsptr[8 * 10] = (int)((tmp24 - tmp14) >> (13 - 2));
    wsptr[8 * 5] = (int)((tmp25 + tmp15) >> (13 - 2));
    wsptr[8 * 9] = (int)((tmp25 - tmp15) >> (13 - 2));
    wsptr[8 * 6] = (int)((tmp26 + tmp16) >> (13 - 2));
    wsptr[8 * 8] = (int)((tmp26 - tmp16) >> (13 - 2));
}
}
