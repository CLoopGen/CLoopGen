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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
for (ctr = 0; ctr < 5; ctr++, inptr += 8, quantptr += 8, wsptr += 5) {
    z3 = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]]));
    z3 <<= 13;
    z3 += ((INT32)1) << (13 - 2 - 1);
    z4 = (((ISLOW_MULT_TYPE)(inptr[indices[4]])) * (quantptr[indices[4]]));
    z1 = ((z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    z2 = ((z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z3 + z1;
    tmp11 = z3 - z2;
    tmp22 = ((z3 - ((z1 - z2) << 1)) >> (13 - 2));
    z2 = (((ISLOW_MULT_TYPE)(inptr[indices[2]])) * (quantptr[indices[2]]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[indices[6]])) * (quantptr[indices[6]]));
    z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp12 = z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp12;
    tmp24 = tmp10 - tmp12;
    tmp21 = tmp11 + tmp13;
    tmp23 = tmp11 - tmp13;
    z1 = (((ISLOW_MULT_TYPE)(inptr[indices[1]])) * (quantptr[indices[1]]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[indices[3]])) * (quantptr[indices[3]]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[indices[5]])) * (quantptr[indices[5]]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[indices[7]])) * (quantptr[indices[7]]));
    tmp11 = z2 + z4;
    tmp13 = z2 - z4;
    tmp12 = ((tmp13) * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5))));
    z5 = z3 << 13;
    z2 = ((tmp11) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5))));
    z4 = z5 + tmp12;
    tmp10 = ((z1) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) + z2 + z4;
    tmp14 = ((z1) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5)))) - z2 + z4;
    z2 = ((tmp11) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5))));
    z4 = z5 - tmp12 - (tmp13 << (13 - 1));
    tmp12 = (z1 - tmp13 - z3) << 2;
    tmp11 = ((z1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) - z2 - z4;
    tmp13 = ((z1) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) - z2 + z4;
    wsptr[0] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[9] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[1] = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[8] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[2] = (int)(tmp22 + tmp12);
    wsptr[7] = (int)(tmp22 - tmp12);
    wsptr[3] = (int)((tmp23 + tmp13) >> (13 - 2));
    wsptr[6] = (int)((tmp23 - tmp13) >> (13 - 2));
    wsptr[4] = (int)((tmp24 + tmp14) >> (13 - 2));
    wsptr[5] = (int)((tmp24 - tmp14) >> (13 - 2));
}
}
