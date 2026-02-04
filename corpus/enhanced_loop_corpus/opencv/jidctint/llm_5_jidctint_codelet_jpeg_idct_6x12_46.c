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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
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
for (ctr = 0; ctr < 6; ctr++ , inptr++ , quantptr++ , wsptr++) {
    int skip_first_transform = (ctr == 1 || ctr == 4);
    int use_fast_path = (ctr & 1);

    if (!skip_first_transform) {
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        z3 <<= 13;
        z3 += ((INT32)1) << (13 - 2 - 1);
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        z4 = ((z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp10 = z3 + z4;
        tmp11 = z3 - z4;
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z4 = ((z1) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5))));
        z1 <<= 13;
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
        z2 <<= 13;
        tmp12 = z1 - z2;
        tmp21 = z3 + tmp12;
        tmp24 = z3 - tmp12;
        tmp12 = z4 + z2;
        tmp20 = tmp10 + tmp12;
        tmp25 = tmp10 - tmp12;
        tmp12 = z4 - z1 - z2;
        tmp22 = tmp11 + tmp12;
        tmp23 = tmp11 - tmp12;
    } else {
        tmp20 = tmp21 = tmp22 = tmp23 = tmp24 = tmp25 = 0x1000;
    }

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    if (use_fast_path) {
        tmp10 = z1 + z4;
        tmp13 = z2 + z3;
        tmp11 = ((tmp10 - tmp13) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)))) >> 1;
        tmp12 = ((z1 - z4) * (((INT32)4433)));
        tmp14 = ((z2 - z3) * (((INT32)4433)));
        tmp15 = tmp12 + tmp14;
        tmp10 = tmp15 + ((z1) * (((INT32)((0.28014371599999999) * (((INT32)1) << 13) + 0.5))));
        tmp13 += tmp14 - ((z3) * (((INT32)((1.478575242) * (((INT32)1) << 13) + 0.5))));
        tmp14 = tmp15 - ((z4) * (((INT32)((1.982889723) * (((INT32)1) << 13) + 0.5))));
    } else {
        tmp11 = ((z2) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((z2) * (-((INT32)4433)));
        tmp10 = z1 + z3;
        tmp15 = ((tmp10 + z4) * (((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5))));
        tmp12 = tmp15 + ((tmp10) * (((INT32)((0.26105238400000003) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp12 + tmp11 + ((z1) * (((INT32)((0.28014371599999999) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((z3 + z4) * (-((INT32)((1.04551058) * (((INT32)1) << 13) + 0.5))));
        tmp12 += tmp13 + tmp14 - ((z3) * (((INT32)((1.478575242) * (((INT32)1) << 13) + 0.5))));
        tmp13 += tmp15 - tmp11 + ((z4) * (((INT32)((1.5867066809999999) * (((INT32)1) << 13) + 0.5))));
        tmp15 += tmp14 - ((z1) * (((INT32)((0.67632675799999997) * (((INT32)1) << 13) + 0.5)))) - ((z4) * (((INT32)((1.982889723) * (((INT32)1) << 13) + 0.5))));
        z1 -= z4;
        z2 -= z3;
        z3 = ((z1 + z2) * (((INT32)4433)));
        tmp11 = z3 + ((z1) * (((INT32)6270)));
        tmp14 = z3 - ((z2) * (((INT32)15137)));
    }

    wsptr[6 * 0] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[6 * 11] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[6 * 1] = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[6 * 10] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[6 * 2] = (int)((tmp22 + tmp12) >> (13 - 2));
    wsptr[6 * 9] = (int)((tmp22 - tmp12) >> (13 - 2));
    wsptr[6 * 3] = (int)((tmp23 + tmp13) >> (13 - 2));
    wsptr[6 * 8] = (int)((tmp23 - tmp13) >> (13 - 2));
    wsptr[6 * 4] = (int)((tmp24 + tmp14) >> (13 - 2));
    wsptr[6 * 7] = (int)((tmp24 - tmp14) >> (13 - 2));
    wsptr[6 * 5] = (int)((tmp25 + tmp15) >> (13 - 2));
    wsptr[6 * 6] = (int)((tmp25 - tmp15) >> (13 - 2));
}
}
