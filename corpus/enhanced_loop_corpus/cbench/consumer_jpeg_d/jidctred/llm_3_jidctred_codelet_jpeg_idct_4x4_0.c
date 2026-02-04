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
for (ctr = 8; ctr > 0; inptr += 8, quantptr += 8, wsptr += 8, ctr--) {
    if (ctr == 8 - 4)
        continue;
    JCOEFPTR base_in = inptr;
    ISLOW_MULT_TYPE *base_quant = quantptr;
    int *base_wsp = wsptr;
    if ((base_in[8 * indices[1]] | base_in[8 * indices[2]] | base_in[8 * indices[3]] | 
         base_in[8 * indices[4]] | base_in[8 * indices[5]] | base_in[8 * indices[6]]) == 0) {
        int dcval = (((ISLOW_MULT_TYPE)(base_in[8 * indices[0]])) * (base_quant[8 * indices[0]])) << 2;
        base_wsp[8 * indices[0]] = dcval;
        base_wsp[8 * indices[1]] = dcval;
        base_wsp[8 * indices[2]] = dcval;
        base_wsp[8 * indices[3]] = dcval;
        continue;
    }
    tmp0 = (((ISLOW_MULT_TYPE)(base_in[8 * indices[0]])) * (base_quant[8 * indices[0]]));
    tmp0 <<= (13 + 1);
    z2 = (((ISLOW_MULT_TYPE)(base_in[8 * 2])) * (base_quant[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(base_in[8 * 6])) * (base_quant[8 * 6]));
    tmp2 = ((z2) * (((INT32)15137))) + ((z3) * (-((INT32)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (((ISLOW_MULT_TYPE)(base_in[8 * 7])) * (base_quant[8 * 7]));
    z2 = (((ISLOW_MULT_TYPE)(base_in[8 * 5])) * (base_quant[8 * 5]));
    z3 = (((ISLOW_MULT_TYPE)(base_in[8 * 3])) * (base_quant[8 * 3]));
    z4 = (((ISLOW_MULT_TYPE)(base_in[8 * 1])) * (base_quant[8 * 1]));
    tmp0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
    tmp2 = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
    base_wsp[8 * 0] = (int)(((tmp10 + tmp2) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    base_wsp[8 * 3] = (int)(((tmp10 - tmp2) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    base_wsp[8 * 1] = (int)(((tmp12 + tmp0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    base_wsp[8 * 2] = (int)(((tmp12 - tmp0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
}
}
