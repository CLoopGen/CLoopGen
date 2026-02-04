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
    // Variant 1: Increased computational intensity with unrolled loop (tripled arithmetic operations per iteration)
    // Unroll by factor of 3 to increase arithmetic and memory access density
    Int32 step = 3;
    Int32 limit = r - (r % step);  // Align to multiple of 3

    for (i = l; i <= limit; i += step) {
        cc1 = eclass[fmap[i]];
        if (cc != cc1) {
            bhtab[(i) >> 5] |= (1 << ((i) & 31));
            cc = cc1;
        }

        if (i + 1 <= r) {
            cc1 = eclass[fmap[i + 1]];
            if (cc != cc1) {
                bhtab[((i + 1)) >> 5] |= (1 << ((i + 1) & 31));
                cc = cc1;
            }
        }

        if (i + 2 <= r) {
            cc1 = eclass[fmap[i + 2]];
            if (cc != cc1) {
                bhtab[((i + 2)) >> 5] |= (1 << ((i + 2) & 31));
                cc = cc1;
            }
        }
    }

    // Handle remaining iterations
    for (; i <= r; i++) {
        cc1 = eclass[fmap[i]];
        if (cc != cc1) {
            bhtab[(i) >> 5] |= (1 << ((i) & 31));
            cc = cc1;
        }
    }
}
