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
    for (ctr = 0; ctr < 16; ctr++) {
        int offset = (ctr % 2 == 0) ? 0 : 1;
        JCOEFPTR local_inptr = inptr + offset;
        ISLOW_MULT_TYPE *local_quantptr = quantptr + offset;
        int *local_wsptr = wsptr + offset;

        tmp0 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (local_quantptr[8 * 0]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
        tmp0 += ((JLONG)1) << (13 - 1 - 1);

        z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 4])) * (local_quantptr[8 * 4]));
        tmp1 = ((z1) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((JLONG)4433)));

        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;

        z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 2])) * (local_quantptr[8 * 2]));
        z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 6])) * (local_quantptr[8 * 6]));
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

        wsptr[8 * 0 + offset] = (int)((tmp20 + tmp0) >> (13 - 1));
        wsptr[8 * 15 + offset] = (int)((tmp20 - tmp0) >> (13 - 1));
        wsptr[8 * 1 + offset] = (int)((tmp21 + tmp1) >> (13 - 1));
        wsptr[8 * 14 + offset] = (int)((tmp21 - tmp1) >> (13 - 1));
        wsptr[8 * 2 + offset] = (int)((tmp22 + tmp2) >> (13 - 1));
        wsptr[8 * 13 + offset] = (int)((tmp22 - tmp2) >> (13 - 1));
        wsptr[8 * 3 + offset] = (int)((tmp23 + tmp3) >> (13 - 1));
        wsptr[8 * 12 + offset] = (int)((tmp23 - tmp3) >> (13 - 1));
        wsptr[8 * 4 + offset] = (int)((tmp24 + tmp10) >> (13 - 1));
        wsptr[8 * 11 + offset] = (int)((tmp24 - tmp10) >> (13 - 1));
        wsptr[8 * 5 + offset] = (int)((tmp25 + tmp11) >> (13 - 1));
        wsptr[8 * 10 + offset] = (int)((tmp25 - tmp11) >> (13 - 1));
        wsptr[8 * 6 + offset] = (int)((tmp26 + tmp12) >> (13 - 1));
        wsptr[8 * 9 + offset] = (int)((tmp26 - tmp12) >> (13 - 1));
        wsptr[8 * 7 + offset] = (int)((tmp27 + tmp13) >> (13 - 1));
        wsptr[8 * 8 + offset] = (int)((tmp27 - tmp13) >> (13 - 1));

        if (ctr % 2 == 1) {
            inptr++;
            quantptr++;
            wsptr++;
        }
    }
}
