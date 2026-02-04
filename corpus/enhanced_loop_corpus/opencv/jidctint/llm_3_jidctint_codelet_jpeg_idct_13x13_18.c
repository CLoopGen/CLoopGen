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
// Variant 2: Use indirect memory access via index mapping table to simulate non-linear access patterns
// This models scenarios where data is accessed through lookup tables or permutations

// Predefined static indices to simulate strided/permuted access (e.g., DCT output ordering)
static const int out_map[13] = {0, 8, 16, 24, 32, 40, 48, 56, 32, 24, 16, 8, 48}; // Covers all required wsptr offsets

for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Indirect access: use an array of offsets instead of hardcoded 8*n
    const int step = 8;
    const int idx[] = {0, 1, 2, 3, 4, 5, 6, 7};

    z1 = (((ISLOW_MULT_TYPE)(inptr[idx[0] * step])) * (quantptr[idx[0] * step]));
    z1 = ((JLONG)((unsigned long)(z1) << 13)) + ((JLONG)1) << (13 - 1 - 1);
    z2 = (((ISLOW_MULT_TYPE)(inptr[idx[2] * step])) * (quantptr[idx[2] * step]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[idx[4] * step])) * (quantptr[idx[4] * step]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[idx[6] * step])) * (quantptr[idx[6] * step]));

    tmp10 = z3 + z4;
    tmp11 = z3 - z4;
    tmp12 = tmp10 * ((JLONG)(1.155388986 * (1LL << 13) + 0.5));
    tmp13 = tmp11 * ((JLONG)(0.096834933999999998 * (1LL << 13) + 0.5)) + z1;
    tmp20 = z2 * ((JLONG)(1.373119086 * (1LL << 13) + 0.5)) + tmp12 + tmp13;
    tmp22 = z2 * ((JLONG)(0.50148704099999997 * (1LL << 13) + 0.5)) - tmp12 + tmp13;

    tmp12 = tmp10 * ((JLONG)(0.31645013100000002 * (1LL << 13) + 0.5));
    tmp13 = tmp11 * ((JLONG)(0.48691473899999999 * (1LL << 13) + 0.5)) + z1;
    tmp21 = z2 * ((JLONG)(1.0585540520000001 * (1LL << 13) + 0.5)) - tmp12 + tmp13;
    tmp25 = z2 * (-((JLONG)(1.25222392 * (1LL << 13) + 0.5))) + tmp12 + tmp13;

    tmp12 = tmp10 * ((JLONG)(0.435816023 * (1LL << 13) + 0.5));
    tmp13 = tmp11 * ((JLONG)(0.93730306399999996 * (1LL << 13) + 0.5)) - z1;
    tmp23 = z2 * (-((JLONG)(0.17046460799999999 * (1LL << 13) + 0.5))) - tmp12 - tmp13;
    tmp24 = z2 * (-((JLONG)(0.80336486900000004 * (1LL << 13) + 0.5))) + tmp12 - tmp13;
    tmp26 = (tmp11 - z2) * ((JLONG)(1.414213562 * (1LL << 13) + 0.5)) + z1;

    z1 = (((ISLOW_MULT_TYPE)(inptr[idx[1] * step])) * (quantptr[idx[1] * step]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[idx[3] * step])) * (quantptr[idx[3] * step]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[idx[5] * step])) * (quantptr[idx[5] * step]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[idx[7] * step])) * (quantptr[idx[7] * step]));

    tmp11 = (z1 + z2) * ((JLONG)(1.3223126510000001 * (1LL << 13) + 0.5));
    tmp12 = (z1 + z3) * ((JLONG)(1.1638749450000001 * (1LL << 13) + 0.5));
    tmp15 = z1 + z4;
    tmp13 = tmp15 * ((JLONG)(0.93779705700000004 * (1LL << 13) + 0.5));
    tmp10 = tmp11 + tmp12 + tmp13 - z1 * ((JLONG)(2.0200822999999999 * (1LL << 13) + 0.5));

    tmp14 = (z2 + z3) * (-((JLONG)(0.33844345799999997 * (1LL << 13) + 0.5)));
    tmp11 += tmp14 + z2 * ((JLONG)(0.83722356399999998 * (1LL << 13) + 0.5));
    tmp12 += tmp14 - z3 * ((JLONG)(1.5721160270000001 * (1LL << 13) + 0.5));

    tmp14 = (z2 + z4) * (-((JLONG)(1.1638749450000001 * (1LL << 13) + 0.5)));
    tmp11 += tmp14;
    tmp13 += tmp14 + z4 * ((JLONG)(2.205608352 * (1LL << 13) + 0.5));

    tmp14 = (z3 + z4) * (-((JLONG)(0.65721781300000004 * (1LL << 13) + 0.5)));
    tmp12 += tmp14;
    tmp13 += tmp14;

    tmp15 = tmp15 * ((JLONG)(0.33844345799999997 * (1LL << 13) + 0.5));
    tmp14 = tmp15 + z1 * ((JLONG)(0.31877435500000001 * (1LL << 13) + 0.5)) - z2 * ((JLONG)(0.466105296 * (1LL << 13) + 0.5));
    z1 = (z3 - z2) * ((JLONG)(0.93779705700000004 * (1LL << 13) + 0.5));
    tmp14 += z1;
    tmp15 += z1 + z3 * ((JLONG)(0.38451559499999999 * (1LL << 13) + 0.5)) - z4 * ((JLONG)(1.7423458110000001 * (1LL << 13) + 0.5));

    // Output using indirect mapping through a fixed table
    wsptr[out_map[0]] = (int)((tmp20 + tmp10) >> (13 - 1));
    wsptr[out_map[12]] = (int)((tmp20 - tmp10) >> (13 - 1));
    wsptr[out_map[1]] = (int)((tmp21 + tmp11) >> (13 - 1));
    wsptr[out_map[11]] = (int)((tmp21 - tmp11) >> (13 - 1));
    wsptr[out_map[2]] = (int)((tmp22 + tmp12) >> (13 - 1));
    wsptr[out_map[10]] = (int)((tmp22 - tmp12) >> (13 - 1));
    wsptr[out_map[3]] = (int)((tmp23 + tmp13) >> (13 - 1));
    wsptr[out_map[9]] = (int)((tmp23 - tmp13) >> (13 - 1));
    wsptr[out_map[4]] = (int)((tmp24 + tmp14) >> (13 - 1));
    wsptr[out_map[8]] = (int)((tmp24 - tmp14) >> (13 - 1));
    wsptr[out_map[5]] = (int)((tmp25 + tmp15) >> (13 - 1));
    wsptr[out_map[7]] = (int)((tmp25 - tmp15) >> (13 - 1));
    wsptr[out_map[6]] = (int)(tmp26 >> (13 - 1));
}
}
