#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index mapping array to simulate indirect access, potentially improving cache behavior
    // or enabling runtime-configurable access patterns.
    static const int idx_map[8] = {0, 2, 4, 6, 1, 3, 5, 7};  // Reordered access pattern
    static const int out_idx[8] = {0, 8, 1, 7, 2, 6, 3, 5}; // Output position mapping

    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[0]])) * (quantptr[8 * idx_map[0]]));
        tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
        tmp0 += ((JLONG)1) << (13 - 1 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[1]])) * (quantptr[8 * idx_map[1]]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[2]])) * (quantptr[8 * idx_map[2]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[3]])) * (quantptr[8 * idx_map[3]]));
        tmp3 = ((z3) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
        tmp1 = tmp0 + tmp3;
        tmp2 = tmp0 - tmp3 - tmp3;
        tmp0 = ((z1 - z2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = tmp2 + tmp0;
        tmp14 = tmp2 - tmp0 - tmp0;
        tmp0 = ((z1 + z2) * (((JLONG)((1.3289260490000001) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((JLONG)((1.0833504410000001) * (((JLONG)1) << 13) + 0.5))));
        tmp3 = ((z2) * (((JLONG)((0.245575608) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = tmp1 + tmp0 - tmp3;
        tmp12 = tmp1 - tmp0 + tmp2;
        tmp13 = tmp1 - tmp2 + tmp3;
        z1 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[4]])) * (quantptr[8 * idx_map[4]]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[5]])) * (quantptr[8 * idx_map[5]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[6]])) * (quantptr[8 * idx_map[6]]));
        z4 = (((ISLOW_MULT_TYPE)(inptr[8 * idx_map[7]])) * (quantptr[8 * idx_map[7]]));
        z2 = ((z2) * (-((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1 + z3) * (((JLONG)((0.90903895499999998) * (((JLONG)1) << 13) + 0.5))));
        tmp3 = ((z1 + z4) * (((JLONG)((0.48368952500000001) * (((JLONG)1) << 13) + 0.5))));
        tmp0 = tmp2 + tmp3 - z2;
        tmp1 = ((z3 - z4) * (((JLONG)((1.392728481) * (((JLONG)1) << 13) + 0.5))));
        tmp2 += z2 - tmp1;
        tmp3 += z2 + tmp1;
        tmp1 = ((z1 - z3 - z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));

        // Apply outputs using indirect indexing
        wsptr[out_idx[0] * 1] = (int)((tmp10 + tmp0) >> (13 - 1));
        wsptr[out_idx[1] * 1] = (int)((tmp10 - tmp0) >> (13 - 1));
        wsptr[out_idx[2] * 1] = (int)((tmp11 + tmp1) >> (13 - 1));
        wsptr[out_idx[3] * 1] = (int)((tmp11 - tmp1) >> (13 - 1));
        wsptr[out_idx[4] * 1] = (int)((tmp12 + tmp2) >> (13 - 1));
        wsptr[out_idx[5] * 1] = (int)((tmp12 - tmp2) >> (13 - 1));
        wsptr[out_idx[6] * 1] = (int)((tmp13 + tmp3) >> (13 - 1));
        wsptr[out_idx[7] * 1] = (int)((tmp13 - tmp3) >> (13 - 1));
        wsptr[4] = (int)((tmp14) >> (13 - 1)); // Fixed center coefficient
    }
}
