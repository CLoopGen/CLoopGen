#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
JCOEFPTR base_in = inptr;
ISLOW_MULT_TYPE *base_quant = quantptr;
int *base_wsptr = wsptr;
for (ctr = 0; ctr < 8; ctr++) {
    int idx = (ctr * 2) % 8; // Non-sequential, strided access with wrap-around
    tmp0 = (((ISLOW_MULT_TYPE)(base_in[idx])) * (base_quant[idx]));
    tmp2 = (((ISLOW_MULT_TYPE)(base_in[(idx + 2) % 8])) * (base_quant[(idx + 2) % 8]));
    tmp10 = (tmp0 + tmp2) << 2;
    tmp12 = (tmp0 - tmp2) << 2;
    z2 = (((ISLOW_MULT_TYPE)(base_in[(idx + 1) % 8])) * (base_quant[(idx + 1) % 8]));
    z3 = (((ISLOW_MULT_TYPE)(base_in[(idx + 3) % 8])) * (base_quant[(idx + 3) % 8]));
    z1 = ((z2 + z3) * (((INT32)4433)));
    z1 += ((INT32)1) << (13 - 2 - 1);
    tmp0 = ((z1 + ((z2) * (((INT32)6270)))) >> (13 - 2));
    tmp2 = ((z1 - ((z3) * (((INT32)15137)))) >> (13 - 2));
    base_wsptr[idx] = (int)(tmp10 + tmp0);
    base_wsptr[(idx + 3) % 8] = (int)(tmp10 - tmp0);
    base_wsptr[(idx + 1) % 8] = (int)(tmp12 + tmp2);
    base_wsptr[(idx + 2) % 8] = (int)(tmp12 - tmp2);
}
}
