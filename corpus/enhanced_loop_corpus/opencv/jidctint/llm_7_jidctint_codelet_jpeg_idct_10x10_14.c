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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Reorder independent computations to eliminate some false dependencies and expose parallelism
    INT32 local_z1, local_z2, local_z3, local_z4, local_z5;
    INT32 t10, t11, t12, t13, t14;
    INT32 u10, u11, u12, u13, u14;
    INT32 v20, v21, v22, v23, v24;

    // Load inputs early and compute independent terms in parallel blocks

    // Block 1: Even-indexed coefficients (0,2,4,6)
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 13;
    z3 += ((INT32)1) << (13 - 2 - 1);
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    local_z1 = ((z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    local_z2 = ((z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
    t10 = z3 + local_z1;
    t11 = z3 - local_z2;
    v22 = ((z3 - ((local_z1 - local_z2) << 1)) >> (13 - 2));

    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    local_z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    t12 = local_z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    t13 = local_z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

    v20 = t10 + t12;
    v24 = t10 - t12;
    v21 = t11 + t13;
    v23 = t11 - t13;

    // Block 2: Odd-indexed coefficients (1,3,5,7) – fully independent of even block
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

    t11 = local_z2 + local_z4;
    t13 = local_z2 - local_z4;
    t12 = ((t13) * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5))));
    local_z5 = local_z3 << 13;

    u10 = ((local_z1) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) 
          + ((t11) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5)))) 
          + (local_z5 + t12);

    u14 = ((local_z1) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5)))) 
          - ((t11) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5)))) 
          + (local_z5 + t12);

    u11 = ((local_z1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) 
          - ((t11) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5)))) 
          - (local_z5 - t12 - (t13 << (13 - 1)));

    u13 = ((local_z1) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) 
          - ((t11) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5)))) 
          + (local_z5 - t12 - (t13 << (13 - 1)));

    t12 = (local_z1 - t13 - local_z3) << 2;

    // Eliminate all global temp variables; use locals only → remove WAW/RAR hazards
    wsptr[8 * 0] = (int)((v20 + u10) >> (13 - 2));
    wsptr[8 * 9] = (int)((v20 - u10) >> (13 - 2));
    wsptr[8 * 1] = (int)((v21 + u11) >> (13 - 2));
    wsptr[8 * 8] = (int)((v21 - u11) >> (13 - 2));
    wsptr[8 * 2] = (int)(v22 + t12);
    wsptr[8 * 7] = (int)(v22 - t12);
    wsptr[8 * 3] = (int)((v23 + u13) >> (13 - 2));
    wsptr[8 * 6] = (int)((v23 - u13) >> (13 - 2));
    wsptr[8 * 4] = (int)((v24 + u14) >> (13 - 2));
    wsptr[8 * 5] = (int)((v24 - u14) >> (13 - 2));
}
}
