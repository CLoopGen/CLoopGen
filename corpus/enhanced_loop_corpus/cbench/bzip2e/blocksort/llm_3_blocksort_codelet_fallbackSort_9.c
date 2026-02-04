#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed stride on bhtab, decoupling index computation
    // We modify the access pattern to use a larger stride in the array indices to increase spatial separation
    const int stride = 64; // Artificially increase stride between accessed words
    for (i = 0; i < 32; i++) {
        // Map logical index to strided physical index in bhtab
        int idx0 = (nblock + 2 * i) >> 5;
        int idx1 = (nblock + 2 * i + 1) >> 5;

        // Apply strided mapping: scatter accesses across bhtab
        UInt32* target0 = &bhtab[idx0 * stride];
        UInt32* target1 = &bhtab[idx1 * stride];

        int bit0 = (nblock + 2 * i) & 31;
        int bit1 = (nblock + 2 * i + 1) & 31;

        target0[0] |= (1U << bit0);
        target1[0] &= ~(1U << bit1);
    }
}
