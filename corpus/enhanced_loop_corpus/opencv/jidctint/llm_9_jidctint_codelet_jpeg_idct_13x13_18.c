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
extern JLONG tmp15;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 16; ctr++) {
    if (ctr < 8) {
        z1 = (((ISLOW_MULT_TYPE)(inptr[ctr])) * (quantptr[ctr]));
        z1 = ((JLONG)((unsigned long)(z1) << (13))) + ((JLONG)1) << (13 - 1 - 1);
        z2 = (((ISLOW_MULT_TYPE)(inptr[ctr + 8])) * (quantptr[ctr + 8]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[ctr + 16])) * (quantptr[ctr + 16]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[ctr + 24])) * (quantptr[ctr + 24]));

        tmp10 = z3 + z4;
        tmp11 = z3 - z4;

        tmp12 = ((tmp10) * (((JLONG)((1.155388986) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = ((tmp11) * (((JLONG)((0.096834933999999998) * (((JLONG)1) << 13) + 0.5)))) + z1;
        tmp20 = ((z2) * (((JLONG)((1.373119086) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
        tmp22 = ((z2) * (((JLONG)((0.50148704099999997) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;

        wsptr[ctr * 8] = (int)((tmp20 + tmp10) >> (13 - 1));
        wsptr[ctr * 8 + 4] = (int)((tmp20 - tmp10) >> (13 - 1));
    } else {
        int idx = ctr - 8;
        z1 = (((ISLOW_MULT_TYPE)(inptr[idx])) * (quantptr[idx]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[idx + 8])) * (quantptr[idx + 8]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[idx + 16])) * (quantptr[idx + 16]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[idx + 24])) * (quantptr[idx + 24]));

        tmp15 = z1 + z4;
        tmp11 = ((z1 + z2) * (((JLONG)((1.3223126510000001) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 + z3) * (((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = ((tmp15) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));

        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((2.0200822999999999) * (((JLONG)1) << 13) + 0.5))));

        wsptr[(idx + 6) * 8] = (int)((tmp10) >> (13 - 1));
    }
}
}
