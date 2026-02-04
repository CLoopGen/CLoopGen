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
for (ctr = 8; ctr > 0; inptr += 2, quantptr += 2, wsptr += 2, ctr -= 2) {
    if (inptr[8 * 0] == 0 && inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 &&
        inptr[8 * 4] == 0 && inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]))) << (1)));
        for (int i = 0; i < 8; ++i) {
            wsptr[i * 8] = dcval;
            if (i < 7) wsptr[(i+1)*8] = dcval;
        }
        continue;
    }

    // First element transformation
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13 + 1)));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp2 = ((z2) * (((JLONG)15137))) + ((z3) * (-((JLONG)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 = ((z1) * (-((JLONG)1730))) + ((z2) * (((JLONG)11893))) + ((z3) * (-((JLONG)17799))) + ((z4) * (((JLONG)8697)));
    tmp2 = ((z1) * (-((JLONG)4176))) + ((z2) * (-((JLONG)4926))) + ((z3) * (((JLONG)7373))) + ((z4) * (((JLONG)20995)));
    wsptr[8 * 0] = (int)(((tmp10 + tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8 * 3] = (int)(((tmp10 - tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8 * 1] = (int)(((tmp12 + tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8 * 2] = (int)(((tmp12 - tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));

    // Second element (unrolled and simplified due to stride)
    if (ctr > 1) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 8])) * (quantptr[8 * 8])); // next row, same column
        tmp0 = ((JLONG)((unsigned long)(tmp0) << (13 + 1)));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 10])) * (quantptr[8 * 10]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 14])) * (quantptr[8 * 14]));
        tmp2 = ((z2) * (((JLONG)15137))) + ((z3) * (-((JLONG)6270)));
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 15])) * (quantptr[8 * 15]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 13])) * (quantptr[8 * 13]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 11])) * (quantptr[8 * 11]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 9])) * (quantptr[8 * 9]));
        tmp0 = ((z1) * (-((JLONG)1730))) + ((z2) * (((JLONG)11893))) + ((z3) * (-((JLONG)17799))) + ((z4) * (((JLONG)8697)));
        tmp2 = ((z1) * (-((JLONG)4176))) + ((z2) * (-((JLONG)4926))) + ((z3) * (((JLONG)7373))) + ((z4) * (((JLONG)20995)));
        wsptr[8 * 8] = (int)(((tmp10 + tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
        wsptr[8 * 11] = (int)(((tmp10 - tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
        wsptr[8 * 9] = (int)(((tmp12 + tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
        wsptr[8 * 10] = (int)(((tmp12 - tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    }
}
}
