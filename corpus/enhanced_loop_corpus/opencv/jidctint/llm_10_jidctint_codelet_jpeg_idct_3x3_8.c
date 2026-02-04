#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp12;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 3; ctr++, inptr += 2, quantptr += 2, wsptr += 6) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
    tmp0 += ((JLONG)1) << (13 - 1 - 1);
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp12 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 = ((tmp12) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));

    wsptr[3 * 0] = (int)((tmp10 + tmp0) >> (13 - 1));
    wsptr[3 * 2] = (int)((tmp10 - tmp0) >> (13 - 1));
    wsptr[3 * 1] = (int)((tmp2) >> (13 - 1));

    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0 + 1])) * (quantptr[8 * 0 + 1]));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
    tmp0 += ((JLONG)1) << (13 - 1 - 1);
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2 + 1])) * (quantptr[8 * 2 + 1]));
    tmp12 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 1 + 1])) * (quantptr[8 * 1 + 1]));
    tmp0 = ((tmp12) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));

    wsptr[3 * 3] = (int)((tmp10 + tmp0) >> (13 - 1));
    wsptr[3 * 5] = (int)((tmp10 - tmp0) >> (13 - 1));
    wsptr[3 * 4] = (int)((tmp2) >> (13 - 1));
}
}
