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
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    tmp13 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp13 = ((JLONG)((unsigned long)(tmp13) << (13)));
    tmp13 += ((JLONG)1) << (13 - 1 - 1);
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp10 = ((z2 - z3) * (((JLONG)((0.88174773399999995) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = ((z1 - z2) * (((JLONG)((0.31469212299999999) * (((JLONG)1) << 13) + 0.5))));
    tmp11 = tmp10 + tmp12 + tmp13 - ((z2) * (((JLONG)((1.841218003) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = z1 + z3;
    z2 -= tmp0;
    tmp0 = ((tmp0) * (((JLONG)((1.274162392) * (((JLONG)1) << 13) + 0.5)))) + tmp13;
    tmp10 += tmp0 - ((z3) * (((JLONG)((0.077722535999999995) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp0 - ((z1) * (((JLONG)((2.4706022490000001) * (((JLONG)1) << 13) + 0.5))));
    tmp13 += ((z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

    // Reduced computation: skip second half involving odd indices (z1, z2, z3 from odd positions)
    // Approximate output using simplified symmetric assignment
    wsptr[7 * 0] = (int)(tmp13 >> (13 - 1));
    wsptr[7 * 6] = wsptr[7 * 0];
    wsptr[7 * 1] = (int)(tmp11 >> (13 - 1));
    wsptr[7 * 5] = wsptr[7 * 1];
    wsptr[7 * 2] = (int)(tmp12 >> (13 - 1));
    wsptr[7 * 4] = wsptr[7 * 2];
    wsptr[7 * 3] = (int)(tmp10 >> (13 - 1));
}
}
