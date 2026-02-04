#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *fmap;
extern UInt32 *eclass;
extern UInt32 *bhtab;
extern Int32 i;
extern Int32 l;
extern Int32 r;
extern Int32 cc;
extern Int32 cc1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Scatter/Gather-like) Access using an auxiliary index array (simulated via offset)
    // Assume we access fmap with indices from a permuted order: use i XOR 16 to create non-consecutive indirect pattern
    UInt32 mask = 0xFFFF; // limit to reasonable range
    for (i = l; i <= r; i++) {
        UInt32 j = (i ^ 0x10) & mask; // synthetic indirect access pattern
        if (j > r) continue; // ensure within bounds
        cc1 = eclass[fmap[j]];
        if (cc != cc1) {
            bhtab[(j) >> 5] |= (1 << ((j) & 31));
            cc = cc1;
        }
    }
}
