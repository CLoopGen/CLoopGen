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
        k = fmap[i] - H;
        if (k >= nblock)
            continue;
        if (k < 0)
            k += nblock;
        if ((bhtab[(i) >> 5] & (1 << ((i) & 31))))
            j = i;
        eclass[k] = j;
        // Additional arithmetic to increase computational intensity
        k = (k * 3 + 1) >> 1;
        if (k < nblock)
            eclass[k] = (j ^ fmap[i]) % nblock;
    }
}
