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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access to fully consecutive layout by precomputing base pointers and using flat indexing
JCOEFPTR in_base = inptr;
ISLOW_MULT_TYPE *quant_base = quantptr;
int *ws_base = wsptr;

for (ctr = 0; ctr < 8; ctr++) {
    INT32 i0 = ctr + 8*0, i1 = ctr + 8*1, i2 = ctr + 8*2, i3 = ctr + 8*3, i4 = ctr + 8*4, i5 = ctr + 8*5;

    tmp10 = (((ISLOW_MULT_TYPE)(in_base[i0])) * (quant_base[i0]));
    tmp10 <<= 13;
    tmp10 += ((INT32)1) << (13 - 2 - 1);

    tmp12 = (((ISLOW_MULT_TYPE)(in_base[i4])) * (quant_base[i4]));
    tmp20 = ((tmp12) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp11 = tmp10 + tmp20;
    tmp21 = ((tmp10 - tmp20 - tmp20) >> (13 - 2));

    tmp20 = (((ISLOW_MULT_TYPE)(in_base[i2])) * (quant_base[i2]));
    tmp10 = ((tmp20) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    tmp20 = tmp11 + tmp10;
    tmp22 = tmp11 - tmp10;

    z1 = (((ISLOW_MULT_TYPE)(in_base[i1])) * (quant_base[i1]));
    z2 = (((ISLOW_MULT_TYPE)(in_base[i3])) * (quant_base[i3]));
    z3 = (((ISLOW_MULT_TYPE)(in_base[i5])) * (quant_base[i5]));

    tmp11 = ((z1 + z3) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp11 + ((z1 + z2) << 13);
    tmp12 = tmp11 + ((z3 - z2) << 13);
    tmp11 = (z1 - z2 - z3) << 2;

    ws_base[i0] = (int)((tmp20 + tmp10) >> (13 - 2));
    ws_base[i5] = (int)((tmp20 - tmp10) >> (13 - 2));
    ws_base[i1] = (int)(tmp21 + tmp11);
    ws_base[i4] = (int)(tmp21 - tmp11);
    ws_base[i2] = (int)((tmp22 + tmp12) >> (13 - 2));
    ws_base[i3] = (int)((tmp22 - tmp12) >> (13 - 2));

    inptr++; quantptr++; wsptr++;
}
}
