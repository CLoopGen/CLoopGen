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
    // Variant 2: Indirect Memory Access Pattern
    // Use an auxiliary index array to access fmap, bhtab, and eclass indirectly
    // Simulate indirect access using a precomputed permutation (conceptual; indices follow non-sequential order)
    // Here, we use reverse order indexing as a form of indirect access pattern
    for (i = 0; i < nblock; i++) {
        Int32 rev_idx = nblock - 1 - i;  // Reverse traversal for indirect-like access
        if ((bhtab[(rev_idx) >> 5] & (1 << ((rev_idx) & 31))))
            j = rev_idx;
        k = fmap[rev_idx] - H;
        if (k < 0)
            k += nblock;
        eclass[k] = j;
    }
}
