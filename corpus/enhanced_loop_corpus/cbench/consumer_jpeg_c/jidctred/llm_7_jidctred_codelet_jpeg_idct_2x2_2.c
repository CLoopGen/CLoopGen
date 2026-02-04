#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern INT32 z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_wsptr0, temp_wsptr1;
for (ctr = 8; ctr > 0; ctr--, inptr++, quantptr++, wsptr++) {
    if (ctr == 8 - 2 || ctr == 8 - 4 || ctr == 8 - 6)
        continue;
    if ((inptr[8 * 1] | inptr[8 * 3] | inptr[8 * 5] | inptr[8 * 7]) == 0) {
        int dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
        temp_wsptr0 = dcval;
        temp_wsptr1 = dcval;
    } else {
        INT32 local_tmp10, local_tmp0, local_z1;
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        local_tmp10 = local_z1 << (13 + 2);
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
        local_tmp0 = ((local_z1) * (-((INT32)5906)));
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        local_tmp0 += ((local_z1) * (((INT32)6967)));
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        local_tmp0 += ((local_z1) * (-((INT32)10426)));
        local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        local_tmp0 += ((local_z1) * (((INT32)29692)));
        temp_wsptr0 = (int)(((local_tmp10 + local_tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
        temp_wsptr1 = (int)(((local_tmp10 - local_tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
    }
    wsptr[8 * 0] = temp_wsptr0;
    wsptr[8 * 1] = temp_wsptr1;
}

}
