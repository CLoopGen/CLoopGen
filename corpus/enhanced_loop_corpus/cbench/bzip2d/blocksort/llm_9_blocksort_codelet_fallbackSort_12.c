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
    // Variant 2: Reduced effective trip count with stride-based sampling
    // Process every 4th element to reduce computational load and cache pressure
    Int32 stride = 4;

    // Adjust starting index to align with original logic as much as possible
    Int32 start = (l + stride - 1) & ~(stride - 1);  // Round up to next multiple of 4
    if (l % stride == 0) start = l;

    for (i = start; i <= r; i += stride) {
        cc1 = eclass[fmap[i]];
        if (cc != cc1) {
            bhtab[(i) >> 5] |= (1 << ((i) & 31));
            cc = cc1;
        }
    }

    // Ensure at least the first element is processed if range is small
    if (l <= r && start > l) {
        i = l;
        cc1 = eclass[fmap[i]];
        if (cc != cc1) {
            bhtab[(i) >> 5] |= (1 << ((i) & 31));
            cc = cc1;
        }
    }
}
