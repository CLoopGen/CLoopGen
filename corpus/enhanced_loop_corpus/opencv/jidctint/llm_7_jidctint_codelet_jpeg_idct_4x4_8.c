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
INT32 temp_store[4]; // Introduce local temporaries to alter data dependencies
for (ctr = 0; ctr < 4; ctr++, inptr++, quantptr++, wsptr++) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp10 = (tmp0 + tmp2) << 2;
    tmp12 = (tmp0 - tmp2) << 2;

    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    z1 = ((z2 + z3) * (((INT32)4433))) + (((INT32)1) << (13 - 2 - 1));

    // Reorder computation and introduce temporary storage to break WAW dependency on tmp0/tmp2
    temp_store[0] = ((z1 + (z2 * ((INT32)6270))) >> (13 - 2)); // was tmp0
    temp_store[1] = ((z1 - (z3 * ((INT32)15137))) >> (13 - 2)); // was tmp2

    // Use stored values with modified access pattern to change RAW dependencies
    wsptr[4 * 0] = (int)(tmp10 + temp_store[0]);
    wsptr[4 * 3] = (int)(tmp10 - temp_store[0]);
    wsptr[4 * 1] = (int)(tmp12 + temp_store[1]);
    wsptr[4 * 2] = (int)(tmp12 - temp_store[1]);
}
}
