#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp15;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Eliminate some RAW dependencies by precomputing values earlier and reordering operations
    JCOEFPTR local_inptr = inptr;
    ISLOW_MULT_TYPE *local_quantptr = quantptr;
    int *local_wsptr = wsptr;

    z1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (local_quantptr[8 * 0]));
    z1 = ((JLONG)((unsigned long)(z1) << (13))) + ((JLONG)1) << (13 - 1 - 1);
    z2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 2])) * (local_quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 4])) * (local_quantptr[8 * 4]));
    z4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 6])) * (local_quantptr[8 * 6]));

    // Preload odd-indexed coefficients to reduce later dependency chains
    JLONG preload_z1_odd = (((ISLOW_MULT_TYPE)(local_inptr[8 * 1])) * (local_quantptr[8 * 1]));
    JLONG preload_z2_odd = (((ISLOW_MULT_TYPE)(local_inptr[8 * 3])) * (local_quantptr[8 * 3]));
    JLONG preload_z3_odd = (((ISLOW_MULT_TYPE)(local_inptr[8 * 5])) * (local_quantptr[8 * 5]));
    JLONG preload_z4_odd = (((ISLOW_MULT_TYPE)(local_inptr[8 * 7])) * (local_quantptr[8 * 7]));

    tmp10 = z3 + z4;
    tmp11 = z3 - z4;

    // Reorder computation to break WAW on tmp12, tmp13, etc., using temporaries
    JLONG t12_a = ((tmp10) * (((JLONG)((1.155388986) * (((JLONG)1) << 13) + 0.5))));
    JLONG t13_a = ((tmp11) * (((JLONG)((0.096834933999999998) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp20 = ((z2) * (((JLONG)((1.373119086) * (((JLONG)1) << 13) + 0.5)))) + t12_a + t13_a;
    tmp22 = ((z2) * (((JLONG)((0.50148704099999997) * (((JLONG)1) << 13) + 0.5)))) - t12_a + t13_a;

    JLONG t12_b = ((tmp10) * (((JLONG)((0.31645013100000002) * (((JLONG)1) << 13) + 0.5))));
    JLONG t13_b = ((tmp11) * (((JLONG)((0.48691473899999999) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp21 = ((z2) * (((JLONG)((1.0585540520000001) * (((JLONG)1) << 13) + 0.5)))) - t12_b + t13_b;
    tmp25 = ((z2) * (-((JLONG)((1.25222392) * (((JLONG)1) << 13) + 0.5)))) + t12_b + t13_b;

    JLONG t12_c = ((tmp10) * (((JLONG)((0.435816023) * (((JLONG)1) << 13) + 0.5))));
    JLONG t13_c = ((tmp11) * (((JLONG)((0.93730306399999996) * (((JLONG)1) << 13) + 0.5)))) - z1;
    tmp23 = ((z2) * (-((JLONG)((0.17046460799999999) * (((JLONG)1) << 13) + 0.5)))) - t12_c - t13_c;
    tmp24 = ((z2) * (-((JLONG)((0.80336486900000004) * (((JLONG)1) << 13) + 0.5)))) + t12_c - t13_c;
    tmp26 = ((tmp11 - z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5)))) + z1;

    // Now use preloaded odd values without waiting for prior computations
    z1 = preload_z1_odd;
    z2 = preload_z2_odd;
    z3 = preload_z3_odd;
    z4 = preload_z4_odd;

    tmp11 = ((z1 + z2) * (((JLONG)((1.3223126510000001) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = ((z1 + z3) * (((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp15 = z1 + z4;
    tmp13 = ((tmp15) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((2.0200822999999999) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2 + z3) * (-((JLONG)((0.33844345799999997) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += tmp14 + ((z2) * (((JLONG)((0.83722356399999998) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp14 - ((z3) * (((JLONG)((1.5721160270000001) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2 + z4) * (-((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += tmp14;
    tmp13 += tmp14 + ((z4) * (((JLONG)((2.205608352) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z3 + z4) * (-((JLONG)((0.65721781300000004) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp14;
    tmp13 += tmp14;
    tmp15 = ((tmp15) * (((JLONG)((0.33844345799999997) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = tmp15 + ((z1) * (((JLONG)((0.31877435500000001) * (((JLONG)1) << 13) + 0.5)))) - ((z2) * (((JLONG)((0.466105296) * (((JLONG)1) << 13) + 0.5))));
    z1 = ((z3 - z2) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));
    tmp14 += z1;
    tmp15 += z1 + ((z3) * (((JLONG)((0.38451559499999999) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.7423458110000001) * (((JLONG)1) << 13) + 0.5))));

    // Store results with shuffled access pattern to remove false dependencies
    int out_indices[] = {0, 12, 1, 11, 2, 10, 3, 9, 4, 8, 5, 7, 6};
    int* ordered_ptrs[13];
    for (int i = 0; i < 13; i++) {
        ordered_ptrs[i] = &local_wsptr[8 * out_indices[i]];
    }

    *ordered_ptrs[0] = (int)((tmp20 + tmp10) >> (13 - 1));
    *ordered_ptrs[1] = (int)((tmp20 - tmp10) >> (13 - 1));
    *ordered_ptrs[2] = (int)((tmp21 + tmp11) >> (13 - 1));
    *ordered_ptrs[3] = (int)((tmp21 - tmp11) >> (13 - 1));
    *ordered_ptrs[4] = (int)((tmp22 + tmp12) >> (13 - 1));
    *ordered_ptrs[5] = (int)((tmp22 - tmp12) >> (13 - 1));
    *ordered_ptrs[6] = (int)((tmp23 + tmp13) >> (13 - 1));
    *ordered_ptrs[7] = (int)((tmp23 - tmp13) >> (13 - 1));
    *ordered_ptrs[8] = (int)((tmp24 + tmp14) >> (13 - 1));
    *ordered_ptrs[9] = (int)((tmp24 - tmp14) >> (13 - 1));
    *ordered_ptrs[10] = (int)((tmp25 + tmp15) >> (13 - 1));
    *ordered_ptrs[11] = (int)((tmp25 - tmp15) >> (13 - 1));
    *ordered_ptrs[12] = (int)((tmp26) >> (13 - 1));
}
}
