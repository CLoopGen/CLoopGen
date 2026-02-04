#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride simulation via indirect indexing
    // Use an auxiliary array to define access order, creating non-sequential but predictable pattern
    // This simulates a more complex memory access behavior while maintaining correctness
    Int32 access_sequence[64];
    for (i = 0; i < 32; i++) {
        access_sequence[2*i]   = (nblock + 2 * i) >> 5;
        access_sequence[2*i+1] = (nblock + 2 * i + 1) >> 5;
    }

    for (i = 0; i < 32; i++) {
        Int32 idx1 = access_sequence[2*i];
        Int32 bit1 = (nblock + 2 * i) & 31;
        bhtab[idx1] |= (1 << bit1);

        Int32 idx2 = access_sequence[2*i+1];
        Int32 bit2 = (nblock + 2 * i + 1) & 31;
        bhtab[idx2] &= ~(1 << bit2);
    }
}
