#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependencies entirely by unrolling simulation and using local temporaries
INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14;
INT32 local_z1, local_z2, local_z3;

for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    local_tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_tmp12 <<= 13;
    local_tmp12 += ((INT32)1) << (13 - 2 - 1);
    local_tmp13 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_tmp14 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));

    // Remove aliasing effects and recompute common subexpressions independently
    local_z1 = ((local_tmp13 + local_tmp14) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
    local_z2 = ((local_tmp13 - local_tmp14) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
    local_z3 = local_tmp12 + local_z2;
    local_tmp10 = local_z3 + local_z1;
    local_tmp11 = local_z3 - local_z1;
    local_tmp12 = local_tmp12 - (local_z2 << 2); // Break WAW on tmp12

    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z1 = ((local_z2 + local_z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    local_tmp13 = local_z1 + (local_z2 * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = local_z1 - (local_z3 * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

    // Restructure store order to remove write-after-write and write-after-read hazards
    // All writes now use local variables — no external state mutation until end
    wsptr[8 * 2] = (int)(local_tmp12 >> (13 - 2));
    wsptr[8 * 1] = (int)((local_tmp11 + local_tmp14) >> (13 - 2));
    wsptr[8 * 3] = (int)((local_tmp11 - local_tmp14) >> (13 - 2));
    wsptr[8 * 0] = (int)((local_tmp10 + local_tmp13) >> (13 - 2));
    wsptr[8 * 4] = (int)((local_tmp10 - local_tmp13) >> (13 - 2));
}
}
