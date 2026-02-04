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
extern INT32 *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Fixed Offset Pattern (simulating non-unit stride over input arrays)
    ptrdiff_t stride = 4;  // Simulate a strided traversal context
    JCOEFPTR in_base = inptr;
    ISLOW_MULT_TYPE *quant_base = quantptr;
    INT32 *ws_base = wsptr;

    for (ctr = 0; ctr < 2; ctr++) {
        int idx = ctr * stride;

        tmp0 = (((ISLOW_MULT_TYPE)(in_base[idx + 8 * 0])) * (quant_base[idx + 8 * 0]));
        tmp2 = (((ISLOW_MULT_TYPE)(in_base[idx + 8 * 2])) * (quant_base[idx + 8 * 2]));
        tmp10 = (tmp0 + tmp2) << 13;
        tmp12 = (tmp0 - tmp2) << 13;

        z2 = (((ISLOW_MULT_TYPE)(in_base[idx + 8 * 1])) * (quant_base[idx + 8 * 1]));
        z3 = (((ISLOW_MULT_TYPE)(in_base[idx + 8 * 3])) * (quant_base[idx + 8 * 3]));
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp0 = z1 + ((z2) * (((INT32)6270)));
        tmp2 = z1 - ((z3) * (((INT32)15137)));

        ws_base[idx + 2 * 0] = tmp10 + tmp0;
        ws_base[idx + 2 * 3] = tmp10 - tmp0;
        ws_base[idx + 2 * 1] = tmp12 + tmp2;
        ws_base[idx + 2 * 2] = tmp12 - tmp2;
    }
}
