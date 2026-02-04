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
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (Indexed) Memory Access via Precomputed Indices
    // Use lookup tables for both input/quantization access and output storage
    // This simulates scenarios where memory access patterns are irregular or data-dependent.

    // Precomputed index mappings for strided access (simulating scattered input layout)
    static const int idx_even[4] = {0, 2*8, 4*8, 6*8}; // Maps to inptr[0], [16], [32], [48]
    static const int idx_odd[3]  = {1*8, 3*8, 5*8};   // Maps to inptr[8], [24], [40]
    static const int out_idx[7] = {0, 6, 1, 5, 2, 4, 3}; // Custom output order

    int indices[7];
    for (int i = 0; i < 7; i++) {
        indices[i] = i * 7; // Simulate non-trivial base offsets for wsptr
    }

    for (ctr = 0; ctr < 7; ctr++) {
        // Indirect access using index arrays
        tmp13 = (((ISLOW_MULT_TYPE)(inptr[idx_even[0]])) * (quantptr[idx_even[0]]));
        tmp13 = ((JLONG)((unsigned long)(tmp13) << 13));
        tmp13 += ((JLONG)1) << (13 - 1 - 1);

        z1 = (((ISLOW_MULT_TYPE)(inptr[idx_even[1]])) * (quantptr[idx_even[1]])); // 2*8
        z2 = (((ISLOW_MULT_TYPE)(inptr[idx_even[2]])) * (quantptr[idx_even[2]])); // 4*8
        z3 = (((ISLOW_MULT_TYPE)(inptr[idx_even[3]])) * (quantptr[idx_even[3]])); // 6*8

        tmp10 = ((z2 - z3) * (((JLONG)((0.88174773399999995) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((JLONG)((0.31469212299999999) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = tmp10 + tmp12 + tmp13 - ((z2) * (((JLONG)((1.841218003) * (((JLONG)1) << 13) + 0.5))));

        tmp0 = z1 + z3;
        z2 -= tmp0;
        tmp0 = ((tmp0) * (((JLONG)((1.274162392) * (((JLONG)1) << 13) + 0.5)))) + tmp13;

        tmp10 += tmp0 - ((z3) * (((JLONG)((0.077722535999999995) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += tmp0 - ((z1) * (((JLONG)((2.4706022490000001) * (((JLONG)1) << 13) + 0.5))));
        tmp13 += ((z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

        z1 = (((ISLOW_MULT_TYPE)(inptr[idx_odd[0]])) * (quantptr[idx_odd[0]])); // 1*8
        z2 = (((ISLOW_MULT_TYPE)(inptr[idx_odd[1]])) * (quantptr[idx_odd[1]])); // 3*8
        z3 = (((ISLOW_MULT_TYPE)(inptr[idx_odd[2]])) * (quantptr[idx_odd[2]])); // 5*8

        tmp1 = ((z1 + z2) * (((JLONG)((0.93541434700000003) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1 - z2) * (((JLONG)((0.17026233900000001) * (((JLONG)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;

        tmp2 = ((z2 + z3) * (-((JLONG)((1.3787562760000001) * (((JLONG)1) << 13) + 0.5))));
        tmp1 += tmp2;

        z2 = ((z1 + z3) * (((JLONG)((0.61360426800000001) * (((JLONG)1) << 13) + 0.5))));
        tmp0 += z2;
        tmp2 += z2 + ((z3) * (((JLONG)((1.870828693) * (((JLONG)1) << 13) + 0.5))));

        // Scattered write using indirect indexing
        wsptr[indices[out_idx[0]]] = (int)((tmp10 + tmp0) >> (13 - 1));
        wsptr[indices[out_idx[1]]] = (int)((tmp10 - tmp0) >> (13 - 1));
        wsptr[indices[out_idx[2]]] = (int)((tmp11 + tmp1) >> (13 - 1));
        wsptr[indices[out_idx[3]]] = (int)((tmp11 - tmp1) >> (13 - 1));
        wsptr[indices[out_idx[4]]] = (int)((tmp12 + tmp2) >> (13 - 1));
        wsptr[indices[out_idx[5]]] = (int)((tmp12 - tmp2) >> (13 - 1));
        wsptr[indices[out_idx[6]]] = (int)((tmp13) >> (13 - 1));

        // Advance external pointers as originally intended
        inptr++;
        quantptr++;
        wsptr += 7;
    }
}
