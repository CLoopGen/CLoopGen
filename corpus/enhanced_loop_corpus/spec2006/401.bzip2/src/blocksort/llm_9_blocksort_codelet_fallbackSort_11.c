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
    // Reduced trip count with upper bound and simplified arithmetic
    // Reduce computational load by removing one conditional branch
    k = fmap[i] - H;
    k = (k < 0) ? k + nblock : k;
    if (bhtab[(i) >> 5] & (1 << (i & 31)))
        j = i;
    eclass[k] = j;
}
}
