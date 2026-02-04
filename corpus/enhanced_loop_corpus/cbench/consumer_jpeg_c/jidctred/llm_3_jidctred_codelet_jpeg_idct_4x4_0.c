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
int indices[] = {0, 1, 2, 3, 5, 6, 7};
for (ctr = 8; ctr > 0; inptr++ , quantptr++ , wsptr++ , ctr--) {
    if (ctr == 8 - 4)
        continue;
    if ((inptr[indices[1]*8] | inptr[indices[2]*8] | inptr[indices[3]*8] | 
         inptr[indices[4]*8] | inptr[indices[5]*8] | inptr[indices[6]*8]) == 0) {
        int dcval = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0])) << 2;
        wsptr[0] = dcval;
        wsptr[1] = dcval;
        wsptr[2] = dcval;
        wsptr[3] = dcval;
        continue;
    }
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
    tmp0 <<= (13 + 1);
    z2 = (((ISLOW_MULT_TYPE)(inptr[2*8])) * (quantptr[2*8]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[6*8])) * (quantptr[6*8]));
    tmp2 = ((z2) * (((INT32)15137))) + ((z3) * (-((INT32)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (((ISLOW_MULT_TYPE)(inptr[7*8])) * (quantptr[7*8]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[5*8])) * (quantptr[5*8]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[3*8])) * (quantptr[3*8]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[1*8])) * (quantptr[1*8]));
    tmp0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
    tmp2 = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
    wsptr[0] = (int)(((tmp10 + tmp2) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    wsptr[3] = (int)(((tmp10 - tmp2) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    wsptr[1] = (int)(((tmp12 + tmp0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    wsptr[2] = (int)(((tmp12 - tmp0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
}
}
