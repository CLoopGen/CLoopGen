#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ctr++ , inptr += 8 , quantptr += 8 , wsptr++) {
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
    tmp12 = ((JLONG)((unsigned long)(tmp12) << (13)));
    tmp12 += ((JLONG)1) << (13 - 1 - 1);
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[2])) * (quantptr[2]));
    tmp1 = (((ISLOW_MULT_TYPE)(inptr[4])) * (quantptr[4]));
    z1 = ((tmp0 + tmp1) * (((JLONG)((0.790569415) * (((JLONG)1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp1) * (((JLONG)((0.35355339099999999) * (((JLONG)1) << 13) + 0.5))));
    z3 = tmp12 + z2;
    tmp10 = z3 + z1;
    tmp11 = z3 - z1;
    tmp12 -= ((JLONG)((unsigned long)(z2) << (2)));
    z2 = (((ISLOW_MULT_TYPE)(inptr[1])) * (quantptr[1]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[3])) * (quantptr[3]));
    z1 = ((z2 + z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = z1 + ((z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
    tmp1 = z1 - ((z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
    wsptr[0] = (int)((tmp10 + tmp0) >> (13 - 1));
    wsptr[4] = (int)((tmp10 - tmp0) >> (13 - 1));
    wsptr[1] = (int)((tmp11 + tmp1) >> (13 - 1));
    wsptr[3] = (int)((tmp11 - tmp1) >> (13 - 1));
    wsptr[2] = (int)((tmp12) >> (13 - 1));
}
}
