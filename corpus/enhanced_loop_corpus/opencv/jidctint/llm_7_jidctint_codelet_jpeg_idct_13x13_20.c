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
extern INT32 tmp15;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
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
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Eliminate some loop-carried dependencies by privatizing variables with array indexing
    INT32 local_z1, local_z2, local_z3, local_z4;
    INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14, local_tmp15;
    INT32 local_tmp20, local_tmp21, local_tmp22, local_tmp23, local_tmp24, local_tmp25, local_tmp26;

    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_z1 <<= 13;
    local_z1 += ((INT32)1) << (13 - 2 - 1);
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    local_tmp10 = local_z3 + local_z4;
    local_tmp11 = local_z3 - local_z4;
    local_tmp12 = ((local_tmp10) * (((INT32)((1.155388986) * (((INT32)1) << 13) + 0.5))));
    local_tmp13 = ((local_tmp11) * (((INT32)((0.096834933999999998) * (((INT32)1) << 13) + 0.5)))) + local_z1;
    local_tmp20 = ((local_z2) * (((INT32)((1.373119086) * (((INT32)1) << 13) + 0.5)))) + local_tmp12 + local_tmp13;
    local_tmp22 = ((local_z2) * (((INT32)((0.50148704099999997) * (((INT32)1) << 13) + 0.5)))) - local_tmp12 + local_tmp13;
    local_tmp12 = ((local_tmp10) * (((INT32)((0.31645013100000002) * (((INT32)1) << 13) + 0.5))));
    local_tmp13 = ((local_tmp11) * (((INT32)((0.48691473899999999) * (((INT32)1) << 13) + 0.5)))) + local_z1;
    local_tmp21 = ((local_z2) * (((INT32)((1.0585540520000001) * (((INT32)1) << 13) + 0.5)))) - local_tmp12 + local_tmp13;
    local_tmp25 = ((local_z2) * (-((INT32)((1.25222392) * (((INT32)1) << 13) + 0.5)))) + local_tmp12 + local_tmp13;
    local_tmp12 = ((local_tmp10) * (((INT32)((0.435816023) * (((INT32)1) << 13) + 0.5))));
    local_tmp13 = ((local_tmp11) * (((INT32)((0.93730306399999996) * (((INT32)1) << 13) + 0.5)))) - local_z1;
    local_tmp23 = ((local_z2) * (-((INT32)((0.17046460799999999) * (((INT32)1) << 13) + 0.5)))) - local_tmp12 - local_tmp13;
    local_tmp24 = ((local_z2) * (-((INT32)((0.80336486900000004) * (((INT32)1) << 13) + 0.5)))) + local_tmp12 - local_tmp13;
    local_tmp26 = ((local_tmp11 - local_z2) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5)))) + local_z1;

    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    local_tmp11 = ((local_z1 + local_z2) * (((INT32)((1.3223126510000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 = ((local_z1 + local_z3) * (((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp15 = local_z1 + local_z4;
    local_tmp13 = ((local_tmp15) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5))));
    local_tmp10 = local_tmp11 + local_tmp12 + local_tmp13 - ((local_z1) * (((INT32)((2.0200822999999999) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = ((local_z2 + local_z3) * (-((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
    local_tmp11 += local_tmp14 + ((local_z2) * (((INT32)((0.83722356399999998) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 += local_tmp14 - ((local_z3) * (((INT32)((1.5721160270000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = ((local_z2 + local_z4) * (-((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
    local_tmp11 += local_tmp14;
    local_tmp13 += local_tmp14 + ((local_z4) * (((INT32)((2.205608352) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = ((local_z3 + local_z4) * (-((INT32)((0.65721781300000004) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 += local_tmp14;
    local_tmp13 += local_tmp14;
    local_tmp15 = ((local_tmp15) * (((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 = local_tmp15 + ((local_z1) * (((INT32)((0.31877435500000001) * (((INT32)1) << 13) + 0.5)))) - ((local_z2) * (((INT32)((0.466105296) * (((INT32)1) << 13) + 0.5))));
    local_z1 = ((local_z3 - local_z2) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5))));
    local_tmp14 += local_z1;
    local_tmp15 += local_z1 + ((local_z3) * (((INT32)((0.38451559499999999) * (((INT32)1) << 13) + 0.5)))) - ((local_z4) * (((INT32)((1.7423458110000001) * (((INT32)1) << 13) + 0.5))));

    // Remove write-after-write (WAW) hazards by eliminating reuse of global temporaries
    // All computations now use local variables — no cross-iteration dependencies

    wsptr[8 * 0] = (int)((local_tmp20 + local_tmp10) >> (13 - 2));
    wsptr[8 * 12] = (int)((local_tmp20 - local_tmp10) >> (13 - 2));
    wsptr[8 * 1] = (int)((local_tmp21 + local_tmp11) >> (13 - 2));
    wsptr[8 * 11] = (int)((local_tmp21 - local_tmp11) >> (13 - 2));
    wsptr[8 * 2] = (int)((local_tmp22 + local_tmp12) >> (13 - 2));
    wsptr[8 * 10] = (int)((local_tmp22 - local_tmp12) >> (13 - 2));
    wsptr[8 * 3] = (int)((local_tmp23 + local_tmp13) >> (13 - 2));
    wsptr[8 * 9] = (int)((local_tmp23 - local_tmp13) >> (13 - 2));
    wsptr[8 * 4] = (int)((local_tmp24 + local_tmp14) >> (13 - 2));
    wsptr[8 * 8] = (int)((local_tmp24 - local_tmp14) >> (13 - 2));
    wsptr[8 * 5] = (int)((local_tmp25 + local_tmp15) >> (13 - 2));
    wsptr[8 * 7] = (int)((local_tmp25 - local_tmp15) >> (13 - 2));
    wsptr[8 * 6] = (int)((local_tmp26) >> (13 - 2));
}
}
