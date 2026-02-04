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
    // Variant 2: Consecutive forward traversal with prefetching-like pattern using offset indexing
    UInt32 temp_fmap, temp_eclass_val;
    for (i = l; i <= r; i++) {
        temp_fmap = fmap[i];
        temp_eclass_val = eclass[temp_fmap];
        if (cc != temp_eclass_val) {
            bhtab[(i >> 5)] |= (1U << (i & 31));
            cc = temp_eclass_val;
        }
    }
}
