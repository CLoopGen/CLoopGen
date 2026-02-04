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
    // Variant 2: Strided memory access pattern on fmap and eclass
    // Instead of processing i from 0 to nblock-1 in order, traverse with a fixed stride (e.g., 4)
    // Wrap around using modulo arithmetic to cover all elements
    Int32 stride = 4;
    Int32 start, offset;
    UInt32 *local_fmap = fmap;
    UInt32 *local_eclass = eclass;
    Int32 local_nblock = nblock;
    Int32 local_H = H;
    Int32 local_j = 0;

    for (start = 0; start < stride; start++) {
        for (offset = 0; start + offset * stride < local_nblock; offset++) {
            i = start + offset * stride;
            if (bhtab[i >> 5] & (1 << (i & 31)))
                local_j = i;
            k = local_fmap[i] - local_H;
            if (k < 0)
                k += local_nblock;
            local_eclass[k] = local_j;
        }
    }
}
