#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp10;
extern JLONG z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ctr = 8; ctr > 0; inptr++ , quantptr++ , wsptr++ , ctr--) {
    if (ctr == 8 - 2 || ctr == 8 - 4 || ctr == 8 - 6)
        continue;
    if (inptr[8 * 1] == 0 && inptr[8 * 3] == 0 && inptr[8 * 5] == 0 && inptr[8 * 7] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]))) << (1)));
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        continue;
    }
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp10 = ((JLONG)((unsigned long)(z1) << (13 + 2)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    tmp0 = ((z1) * (-((JLONG)5906)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp0 += ((z1) * (((JLONG)6967)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    tmp0 += ((z1) * (-((JLONG)10426)));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 += ((z1) * (((JLONG)29692)));
    wsptr[8 * 0] = (int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 - 1 + 2) - 1))) >> (13 - 1 + 2));
    wsptr[8 * 1] = (int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 - 1 + 2) - 1))) >> (13 - 1 + 2));
}

}
