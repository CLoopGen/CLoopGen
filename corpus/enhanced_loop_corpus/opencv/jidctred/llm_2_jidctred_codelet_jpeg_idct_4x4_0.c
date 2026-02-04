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
for (ctr = 8; ctr > 0; inptr++ , quantptr++ , wsptr++ , ctr--) {
    if (ctr == 8 - 4)
        continue;
    if (inptr[0] == 0 && inptr[16] == 0 && inptr[24] == 0 && inptr[40] == 0 && inptr[48] == 0 && inptr[56] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]))) << (1)));
        wsptr[0] = dcval;
        wsptr[8] = dcval;
        wsptr[16] = dcval;
        wsptr[24] = dcval;
        continue;
    }
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13 + 1)));
    z2 = (((ISLOW_MULT_TYPE)(inptr[16])) * (quantptr[16]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[48])) * (quantptr[48]));
    tmp2 = ((z2) * (((JLONG)15137))) + ((z3) * (-((JLONG)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (((ISLOW_MULT_TYPE)(inptr[56])) * (quantptr[56]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[40])) * (quantptr[40]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[24])) * (quantptr[24]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8])) * (quantptr[8]));
    tmp0 = ((z1) * (-((JLONG)1730))) + ((z2) * (((JLONG)11893))) + ((z3) * (-((JLONG)17799))) + ((z4) * (((JLONG)8697)));
    tmp2 = ((z1) * (-((JLONG)4176))) + ((z2) * (-((JLONG)4926))) + ((z3) * (((JLONG)7373))) + ((z4) * (((JLONG)20995)));
    wsptr[0] = (int)(((tmp10 + tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[24] = (int)(((tmp10 - tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8] = (int)(((tmp12 + tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[16] = (int)(((tmp12 - tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
}
}
