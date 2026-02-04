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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index mapping table to perform non-linear, indirect access to simulate irregular patterns
    // This reflects scenarios like sparse transforms or permuted data layouts.

    static const int index_map_even[4] = {0, 2, 4, 6};   // Original even positions scaled by 8
    static const int index_map_odd[3]  = {1, 3, 5};      // Odd positions
    static const int out_map[7] = {0, 6, 1, 5, 2, 4, 3}; // Output position mapping

    for (ctr = 0; ctr < 8; ctr++) {
        int i_even[4], i_odd[3];
        int o_map[7];

        // Compute actual memory offsets using indirect indexing
        for (int i = 0; i < 4; i++) i_even[i] = index_map_even[i] * 8;
        for (int i = 0; i < 3; i++) i_odd[i]  = index_map_odd[i]  * 8;
        for (int i = 0; i < 7; i++) o_map[i]   = out_map[i]  * 8;

        // Load even-indexed inputs indirectly
        tmp23 = (((ISLOW_MULT_TYPE)(inptr[i_even[0]])) * (quantptr[i_even[0]]));
        tmp23 <<= 13;
        tmp23 += ((INT32)1) << (13 - 2 - 1);
        z1 = (((ISLOW_MULT_TYPE)(inptr[i_even[1]])) * (quantptr[i_even[1]]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[i_even[2]])) * (quantptr[i_even[2]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[i_even[3]])) * (quantptr[i_even[3]]));

        tmp20 = ((z2 - z3) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
        tmp22 = ((z1 - z2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
        tmp21 = tmp20 + tmp22 + tmp23 - ((z2) * (((INT32)((1.841218003) * (((INT32)1) << 13) + 0.5))));

        tmp10 = z1 + z3;
        z2 -= tmp10;
        tmp10 = ((tmp10) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5)))) + tmp23;
        tmp20 += tmp10 - ((z3) * (((INT32)((0.077722535999999995) * (((INT32)1) << 13) + 0.5))));
        tmp22 += tmp10 - ((z1) * (((INT32)((2.4706022490000001) * (((INT32)1) << 13) + 0.5))));
        tmp23 += ((z2) * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));

        // Load odd-indexed inputs indirectly
        z1 = (((ISLOW_MULT_TYPE)(inptr[i_odd[0]])) * (quantptr[i_odd[0]]));
        z2 = (((ISLOW_MULT_TYPE)(inptr[i_odd[1]])) * (quantptr[i_odd[1]]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[i_odd[2]])) * (quantptr[i_odd[2]]));

        tmp11 = ((z1 + z2) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 - tmp12;
        tmp11 += tmp12;
        tmp12 = ((z2 + z3) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
        tmp11 += tmp12;
        z2 = ((z1 + z3) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2;
        tmp12 += z2 + ((z3) * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));

        // Write outputs through indirect addressing
        wsptr[o_map[0]] = (int)((tmp20 + tmp10) >> (13 - 2));
        wsptr[o_map[1]] = (int)((tmp20 - tmp10) >> (13 - 2));
        wsptr[o_map[2]] = (int)((tmp21 + tmp11) >> (13 - 2));
        wsptr[o_map[3]] = (int)((tmp21 - tmp11) >> (13 - 2));
        wsptr[o_map[4]] = (int)((tmp22 + tmp12) >> (13 - 2));
        wsptr[o_map[5]] = (int)((tmp22 - tmp12) >> (13 - 2));
        wsptr[o_map[6]] = (int)((tmp23) >> (13 - 2));

        // Advance pointers normally
        inptr++;
        quantptr++;
        wsptr++;
    }
}
