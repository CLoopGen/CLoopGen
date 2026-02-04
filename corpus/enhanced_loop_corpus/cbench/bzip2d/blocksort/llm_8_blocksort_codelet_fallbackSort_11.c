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
    for (i = 0; i < nblock; i += 2) {
        if (i + 1 < nblock) {
            UInt32 cond1 = bhtab[(i) >> 5] & (1 << ((i) & 31));
            UInt32 cond2 = bhtab[(i+1) >> 5] & (1 << ((i+1) & 31));
            if (cond1)
                j = i;
            k = fmap[i] - H;
            if (k < 0)
                k += nblock;
            eclass[k] = j;
            if (cond2)
                j = i + 1;
            k = fmap[i+1] - H;
            if (k < 0)
                k += nblock;
            eclass[k] = j;
        } else {
            if (bhtab[(i) >> 5] & (1 << ((i) & 31)))
                j = i;
            k = fmap[i] - H;
            if (k < 0)
                k += nblock;
            eclass[k] = j;
        }
    }
}
