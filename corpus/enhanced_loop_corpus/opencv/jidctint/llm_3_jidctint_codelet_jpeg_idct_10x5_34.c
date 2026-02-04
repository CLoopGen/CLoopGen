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



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Introduce an index map to access array elements indirectly, simulating non-sequential or reordered access.
    // This models scenarios like permutation or scatter/gather operations.

    static const int index_map[8] = {0, 2, 4, 1, 3, 5, 6, 7}; // Example permutation of indices

    for (ctr = 0; ctr < 8; ctr++) {
        int idx = index_map[ctr]; // Indirect indexing

        tmp12 = (((ISLOW_MULT_TYPE)(inptr[idx * 8])) * (quantptr[idx * 8]));
        tmp12 <<= 13;
        tmp12 += ((INT32)1) << (13 - 2 - 1);
        tmp13 = (((ISLOW_MULT_TYPE)(inptr[(idx + 0) * 8])) * (quantptr[(idx + 0) * 8])); // redundant but pattern-consistent
        tmp14 = (((ISLOW_MULT_TYPE)(inptr[idx * 8 + 16])) * (quantptr[idx * 8 + 16]));
        z1 = ((tmp13 + tmp14) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp13 - tmp14) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
        z3 = tmp12 + z2;
        tmp10 = z3 + z1;
        tmp11 = z3 - z1;
        tmp12 -= z2 << 2;
        z2 = (((ISLOW_MULT_TYPE)(inptr[idx * 8 + 8])) * (quantptr[idx * 8 + 8]));
        z3 = (((ISLOW_MULT_TYPE)(inptr[idx * 8 + 24])) * (quantptr[idx * 8 + 24]));
        z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        tmp13 = z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
        tmp14 = z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

        // Write results using indirect pattern on output as well
        wsptr[idx * 8 + 0] = (int)((tmp10 + tmp13) >> (13 - 2));
        wsptr[idx * 8 + 4] = (int)((tmp10 - tmp13) >> (13 - 2));
        wsptr[idx * 8 + 1] = (int)((tmp11 + tmp14) >> (13 - 2));
        wsptr[idx * 8 + 3] = (int)((tmp11 - tmp14) >> (13 - 2));
        wsptr[idx * 8 + 2] = (int)((tmp12) >> (13 - 2));

        inptr++; 
        quantptr++; 
        wsptr++;
    }
}
