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
    Int32 prev_eclass_val = 0;
    for (i = 0; i < nblock; i++) {
        j = prev_eclass_val; // Introduce WAW and loop-carried dependency via j
        if ((bhtab[(i) >> 5] & (1 << ((i) & 31))))
            j = i;
        k = fmap[i] - H;
        if (k < 0)
            k += nblock;
        eclass[k] = j;
        prev_eclass_val = eclass[k]; // Create loop-carried dependence: current write affects next iteration
    }
}
