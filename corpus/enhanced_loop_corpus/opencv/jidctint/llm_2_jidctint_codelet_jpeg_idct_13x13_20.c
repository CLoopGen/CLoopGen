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



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (8 * i), reorganize data to be accessed consecutively.
    // Assume input data is pre-reorganized into separate arrays for even and odd indices to allow linear access.
    
    JCOEFPTR inptr_even = inptr;
    JCOEFPTR inptr_odd = inptr + 1;
    ISLOW_MULT_TYPE *quantptr_even = quantptr;
    ISLOW_MULT_TYPE *quantptr_odd = quantptr + 1;

    for (ctr = 0; ctr < 8; ctr++, inptr_even++, inptr_odd++, quantptr_even++, quantptr_odd++, wsptr++) {
        z1 = (((ISLOW_MULT_TYPE)(inptr_even[0])) * (quantptr_even[0]));
        z1 <<= 13;
        z1 += ((INT32)1) << (13 - 2 - 1);
        z2 = (((ISLOW_MULT_TYPE)(inptr_even[2])) * (quantptr_even[2]));
        z3 = (((ISLOW_MULT_TYPE)(inptr_even[4])) * (quantptr_even[4]));
        z4 = (((ISLOW_MULT_TYPE)(inptr_even[6])) * (quantptr_even[6]));
        tmp10 = z3 + z4;
        tmp11 = z3 - z4;
        tmp12 = ((tmp10) * (((INT32)((1.155388986) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((tmp11) * (((INT32)((0.096834933999999998) * (((INT32)1) << 13) + 0.5)))) + z1;
        tmp20 = ((z2) * (((INT32)((1.373119086) * (((INT32)1) << 13) + 0.5)))) + tmp12 + tmp13;
        tmp22 = ((z2) * (((INT32)((0.50148704099999997) * (((INT32)1) << 13) + 0.5)))) - tmp12 + tmp13;
        tmp12 = ((tmp10) * (((INT32)((0.31645013100000002) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((tmp11) * (((INT32)((0.48691473899999999) * (((INT32)1) << 13) + 0.5)))) + z1;
        tmp21 = ((z2) * (((INT32)((1.0585540520000001) * (((INT32)1) << 13) + 0.5)))) - tmp12 + tmp13;
        tmp25 = ((z2) * (-((INT32)((1.25222392) * (((INT32)1) << 13) + 0.5)))) + tmp12 + tmp13;
        tmp12 = ((tmp10) * (((INT32)((0.435816023) * (((INT32)1) << 13) + 0.5))));
        tmp13 = ((tmp11) * (((INT32)((0.93730306399999996) * (((INT32)1) << 13) + 0.5)))) - z1;
        tmp23 = ((z2) * (-((INT32)((0.17046460799999999) * (((INT32)1) << 13) + 0.5)))) - tmp12 - tmp13;
        tmp24 = ((z2) * (-((INT32)((0.80336486900000004) * (((INT32)1) << 13) + 0.5)))) + tmp12 - tmp13;
        tmp26 = ((tmp11 - z2) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5)))) + z1;

        z1 = (((ISLOW_MULT_TYPE)(inptr_odd[0])) * (quantptr_odd[0]));
        z2 = (((ISLOW_MULT_TYPE)(inptr_odd[2])) * (quantptr_odd[2]));
        z3 = (((ISLOW_MULT_TYPE)(inptr_odd[4])) * (quantptr_odd[4]));
        z4 = (((ISLOW_MULT_TYPE)(inptr_odd[6])) * (quantptr_odd[6]));
        tmp11 = ((z1 + z2) * (((INT32)((1.3223126510000001) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 + z3) * (((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
        tmp15 = z1 + z4;
        tmp13 = ((tmp15) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((INT32)((2.0200822999999999) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((z2 + z3) * (-((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp14 + ((z2) * (((INT32)((0.83722356399999998) * (((INT32)1) << 13) + 0.5))));
        tmp12 += tmp14 - ((z3) * (((INT32)((1.5721160270000001) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((z2 + z4) * (-((INT32)((1.1638749450000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp14;
        tmp13 += tmp14 + ((z4) * (((INT32)((2.205608352) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((z3 + z4) * (-((INT32)((0.65721781300000004) * (((INT32)1) << 13) + 0.5))));
        tmp12 += tmp14;
        tmp13 += tmp14;
        tmp15 = ((tmp15) * (((INT32)((0.33844345799999997) * (((INT32)1) << 13) + 0.5))));
        tmp14 = tmp15 + ((z1) * (((INT32)((0.31877435500000001) * (((INT32)1) << 13) + 0.5)))) - ((z2) * (((INT32)((0.466105296) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z3 - z2) * (((INT32)((0.93779705700000004) * (((INT32)1) << 13) + 0.5))));
        tmp14 += z1;
        tmp15 += z1 + ((z3) * (((INT32)((0.38451559499999999) * (((INT32)1) << 13) + 0.5)))) - ((z4) * (((INT32)((1.7423458110000001) * (((INT32)1) << 13) + 0.5))));

        wsptr[0] = (int)((tmp20 + tmp10) >> (13 - 2));
        wsptr[12] = (int)((tmp20 - tmp10) >> (13 - 2));
        wsptr[1] = (int)((tmp21 + tmp11) >> (13 - 2));
        wsptr[11] = (int)((tmp21 - tmp11) >> (13 - 2));
        wsptr[2] = (int)((tmp22 + tmp12) >> (13 - 2));
        wsptr[10] = (int)((tmp22 - tmp12) >> (13 - 2));
        wsptr[3] = (int)((tmp23 + tmp13) >> (13 - 2));
        wsptr[9] = (int)((tmp23 - tmp13) >> (13 - 2));
        wsptr[4] = (int)((tmp24 + tmp14) >> (13 - 2));
        wsptr[8] = (int)((tmp24 - tmp14) >> (13 - 2));
        wsptr[5] = (int)((tmp25 + tmp15) >> (13 - 2));
        wsptr[7] = (int)((tmp25 - tmp15) >> (13 - 2));
        wsptr[6] = (int)(tmp26 >> (13 - 2));
    }
}
