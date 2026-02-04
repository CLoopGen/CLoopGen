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
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential i, access fmap and bhtab with a stride of 4 (unroll-like pattern)
    // Ensure we don't exceed nblock by checking bounds
    Int32 stride = 4;
    for (i = 0; i < nblock; i += stride) {
        for (Int32 s = 0; s < stride && (i + s) < nblock; s++) {
            Int32 idx = i + s;
            if ((bhtab[(idx) >> 5] & (1 << ((idx) & 31))))
                j = idx;
            k = fmap[idx] - H;
            if (k < 0)
                k += nblock;
            eclass[k] = j;
        }
    }
}
