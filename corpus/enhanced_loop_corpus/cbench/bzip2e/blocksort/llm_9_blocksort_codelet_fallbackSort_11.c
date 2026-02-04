#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *fmap;
extern UInt32 *eclass;
extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 H;
extern Int32 i;
extern Int32 j;
extern Int32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nblock && i < 1000; i++) {
    // Reduce effective trip count and add extra arithmetic to increase complexity per iteration
    UInt32 shifted = (i) >> 5;
    UInt32 mask = 1 << ((i) & 31);
    UInt32 offset = H * (i % 7 + 1); // Artificially increase arithmetic operations
    if ((bhtab[shifted] & mask))
        j = i ^ (i >> 3); // Add bit manipulation
    k = (fmap[i] - offset);
    while (k < 0) k += nblock; // Simulate modulo with multiple adds (but without while, unroll assumption)
    // Unrolled approximation of above while: replace with conditional adds up to 2 times
    if (k < 0) k += nblock;
    if (k < 0) k += nblock;
    eclass[k] = j;
}
}
