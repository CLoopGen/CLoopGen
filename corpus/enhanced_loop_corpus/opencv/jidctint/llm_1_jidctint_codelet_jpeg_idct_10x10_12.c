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
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 2; ctr++) {
    for (int inner = 0; inner < 4; inner++) {
        int idx = ctr * 4 + inner;
        JCOEFPTR local_inptr = inptr + idx;
        ISLOW_MULT_TYPE *local_quantptr = quantptr + idx;
        int *local_wsptr = wsptr + idx;

        z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (local_quantptr[8 * 0]));
        z3 = ((JLONG)((unsigned long)(z3) << (13)));
        z3 += ((JLONG)1) << (13 - 1 - 1);
        z4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 4])) * (local_quantptr[8 * 4]));
        z1 = ((z4) * (((JLONG)((1.1441228059999999) * (((JLONG)1) << 13) + 0.5))));
        z2 = ((z4) * (((JLONG)((0.437016024) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = z3 + z1;
        tmp11 = z3 - z2;
        tmp22 = ((z3 - ((JLONG)((unsigned long)(z1 - z2) << (1)))) >> (13 - 1));
        z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 2])) * (local_quantptr[8 * 2]));
        z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 6])) * (local_quantptr[8 * 6]));
        z1 = ((z2 + z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = z1 + ((z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = z1 - ((z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp12;
        tmp24 = tmp10 - tmp12;
        tmp21 = tmp11 + tmp13;
        tmp23 = tmp11 - tmp13;
        z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 1])) * (local_quantptr[8 * 1]));
        z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 3])) * (local_quantptr[8 * 3]));
        z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 5])) * (local_quantptr[8 * 5]));
        z4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 7])) * (local_quantptr[8 * 7]));
        tmp11 = z2 + z4;
        tmp13 = z2 - z4;
        tmp12 = ((tmp13) * (((JLONG)((0.30901699399999999) * (((JLONG)1) << 13) + 0.5))));
        z5 = ((JLONG)((unsigned long)(z3) << (13)));
        z2 = ((tmp11) * (((JLONG)((0.95105651599999996) * (((JLONG)1) << 13) + 0.5))));
        z4 = z5 + tmp12;
        tmp10 = ((z1) * (((JLONG)((1.3968022470000001) * (((JLONG)1) << 13) + 0.5)))) + z2 + z4;
        tmp14 = ((z1) * (((JLONG)((0.22123174200000001) * (((JLONG)1) << 13) + 0.5)))) - z2 + z4;
        z2 = ((tmp11) * (((JLONG)((0.58778525199999998) * (((JLONG)1) << 13) + 0.5))));
        z4 = z5 - tmp12 - ((JLONG)((unsigned long)(tmp13) << (13 - 1)));
        tmp12 = ((JLONG)((unsigned long)(z1 - tmp13 - z3) << (1)));
        tmp11 = ((z1) * (((JLONG)((1.2600735110000001) * (((JLONG)1) << 13) + 0.5)))) - z2 - z4;
        tmp13 = ((z1) * (((JLONG)((0.64203952200000003) * (((JLONG)1) << 13) + 0.5)))) - z2 + z4;
        local_wsptr[8 * 0] = (int)((tmp20 + tmp10) >> (13 - 1));
        local_wsptr[8 * 9] = (int)((tmp20 - tmp10) >> (13 - 1));
        local_wsptr[8 * 1] = (int)((tmp21 + tmp11) >> (13 - 1));
        local_wsptr[8 * 8] = (int)((tmp21 - tmp11) >> (13 - 1));
        local_wsptr[8 * 2] = (int)(tmp22 + tmp12);
        local_wsptr[8 * 7] = (int)(tmp22 - tmp12);
        local_wsptr[8 * 3] = (int)((tmp23 + tmp13) >> (13 - 1));
        local_wsptr[8 * 6] = (int)((tmp23 - tmp13) >> (13 - 1));
        local_wsptr[8 * 4] = (int)((tmp24 + tmp14) >> (13 - 1));
        local_wsptr[8 * 5] = (int)((tmp24 - tmp14) >> (13 - 1));
    }
}
ctr = 8;
inptr += 8;
quantptr += 8;
wsptr += 8;
}
