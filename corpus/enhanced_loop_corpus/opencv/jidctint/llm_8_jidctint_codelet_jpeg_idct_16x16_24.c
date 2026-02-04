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
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 4; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
        tmp0 += ((JLONG)1) << (13 - 1 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        tmp1 = ((z1) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((JLONG)4433)));
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
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

        wsptr[8 * 0] = (int)((tmp20 + tmp0) >> (13 - 1));
        wsptr[8 * 15] = (int)((tmp20 - tmp0) >> (13 - 1));
        wsptr[8 * 1] = (int)((tmp21 + tmp1) >> (13 - 1));
        wsptr[8 * 14] = (int)((tmp21 - tmp1) >> (13 - 1));
        wsptr[8 * 2] = (int)((tmp22 + tmp2) >> (13 - 1));
        wsptr[8 * 13] = (int)((tmp22 - tmp2) >> (13 - 1));
        wsptr[8 * 3] = (int)((tmp23 + tmp3) >> (13 - 1));
        wsptr[8 * 12] = (int)((tmp23 - tmp3) >> (13 - 1));
        wsptr[8 * 4] = (int)((tmp24 + tmp10) >> (13 - 1));
        wsptr[8 * 11] = (int)((tmp24 - tmp10) >> (13 - 1));
        wsptr[8 * 5] = (int)((tmp25 + tmp11) >> (13 - 1));
        wsptr[8 * 10] = (int)((tmp25 - tmp11) >> (13 - 1));
        wsptr[8 * 6] = (int)((tmp26 + tmp12) >> (13 - 1));
        wsptr[8 * 9] = (int)((tmp26 - tmp12) >> (13 - 1));
        wsptr[8 * 7] = (int)((tmp27 + tmp13) >> (13 - 1));
        wsptr[8 * 8] = (int)((tmp27 - tmp13) >> (13 - 1));

        inptr++;
        quantptr++;
        wsptr++;

        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
        tmp0 += ((JLONG)1) << (13 - 1 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        tmp1 = ((z1) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((JLONG)4433)));
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;

        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
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

        wsptr[8 * 0] = (int)((tmp20 + tmp0) >> (13 - 1));
        wsptr[8 * 15] = (int)((tmp20 - tmp0) >> (13 - 1));
        wsptr[8 * 1] = (int)((tmp21 + tmp1) >> (13 - 1));
        wsptr[8 * 14] = (int)((tmp21 - tmp1) >> (13 - 1));
        wsptr[8 * 2] = (int)((tmp22 + tmp2) >> (13 - 1));
        wsptr[8 * 13] = (int)((tmp22 - tmp2) >> (13 - 1));
        wsptr[8 * 3] = (int)((tmp23 + tmp3) >> (13 - 1));
        wsptr[8 * 12] = (int)((tmp23 - tmp3) >> (13 - 1));
        wsptr[8 * 4] = (int)((tmp24 + tmp10) >> (13 - 1));
        wsptr[8 * 11] = (int)((tmp24 - tmp10) >> (13 - 1));
        wsptr[8 * 5] = (int)((tmp25 + tmp11) >> (13 - 1));
        wsptr[8 * 10] = (int)((tmp25 - tmp11) >> (13 - 1));
        wsptr[8 * 6] = (int)((tmp26 + tmp12) >> (13 - 1));
        wsptr[8 * 9] = (int)((tmp26 - tmp12) >> (13 - 1));
        wsptr[8 * 7] = (int)((tmp27 + tmp13) >> (13 - 1));
        wsptr[8 * 8] = (int)((tmp27 - tmp13) >> (13 - 1));
    }
}
