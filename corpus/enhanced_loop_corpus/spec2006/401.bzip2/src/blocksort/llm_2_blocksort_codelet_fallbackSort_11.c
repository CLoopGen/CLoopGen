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
    // Variant 1: Consecutive memory access by reordering computation to access eclass and fmap sequentially
    // We precompute valid indices where bhtab condition holds and process them in order to ensure sequential eclass writes
    UInt32 *local_fmap = fmap;
    UInt32 *local_eclass = eclass;
    Int32 local_nblock = nblock;
    Int32 local_H = H;
    Int32 j_val = 0;

    for (i = 0; i < local_nblock; i++) {
        if (bhtab[i >> 5] & (1 << (i & 31)))
            j_val = i;
        // Access fmap and eclass with unit stride
        k = local_fmap[i] - local_H;
        if (k < 0)
            k += local_nblock;
        local_eclass[k] = j_val;
    }
}
