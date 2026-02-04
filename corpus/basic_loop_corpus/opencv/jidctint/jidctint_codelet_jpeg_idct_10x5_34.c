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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp12 <<= 13;
    tmp12 += ((INT32)1) << (13 - 2 - 1);
    tmp13 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp14 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z1 = ((tmp13 + tmp14) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp13 - tmp14) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
    z3 = tmp12 + z2;
    tmp10 = z3 + z1;
    tmp11 = z3 - z1;
    tmp12 -= z2 << 2;
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp13 = z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    tmp14 = z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));
    wsptr[8 * 0] = (int)((tmp10 + tmp13) >> (13 - 2));
    wsptr[8 * 4] = (int)((tmp10 - tmp13) >> (13 - 2));
    wsptr[8 * 1] = (int)((tmp11 + tmp14) >> (13 - 2));
    wsptr[8 * 3] = (int)((tmp11 - tmp14) >> (13 - 2));
    wsptr[8 * 2] = (int)((tmp12) >> (13 - 2));
}

}
