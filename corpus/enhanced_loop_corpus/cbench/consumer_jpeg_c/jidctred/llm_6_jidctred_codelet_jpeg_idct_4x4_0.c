#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; inptr++ , quantptr++ , wsptr++ , ctr--) {
    if (ctr == 8 - 4) {
        continue;
    }
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 <<= (13 + 1);
    if ((z4 | (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2])) | z3 | (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5])) | tmp2 | (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]))) == 0) {
        int dcval = ((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]))) << 2;
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        continue;
    }
    INT32 local_tmp2 = ((tmp2) * (((INT32)15137))) + ((z3) * (-((INT32)6270)));
    tmp10 = tmp0 + local_tmp2;
    tmp12 = tmp0 - local_tmp2;
    INT32 local_tmp0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
    INT32 local_tmp2b = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
    wsptr[8 * 0] = (int)(((tmp10 + local_tmp2b) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    wsptr[8 * 3] = (int)(((tmp10 - local_tmp2b) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    wsptr[8 * 1] = (int)(((tmp12 + local_tmp0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    wsptr[8 * 2] = (int)(((tmp12 - local_tmp0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
}
}
