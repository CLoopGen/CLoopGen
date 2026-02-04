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
    JLONG temp_dc = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    JLONG temp7 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    JLONG temp5 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    JLONG temp3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    JLONG temp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));

    tmp10 = ((JLONG)((unsigned long)(temp_dc) << (13 + 2)));
    tmp0 = (temp7 * (-((JLONG)5906))) +
           (temp5 * (((JLONG)6967))) +
           (temp3 * (-((JLONG)10426))) +
           (temp1 * (((JLONG)29692)));

    int result0 = (int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 - 1 + 2) - 1))) >> (13 - 1 + 2));
    int result1 = (int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 - 1 + 2) - 1))) >> (13 - 1 + 2));

    wsptr[8 * 0] = result0;
    wsptr[8 * 1] = result1;
}
}
