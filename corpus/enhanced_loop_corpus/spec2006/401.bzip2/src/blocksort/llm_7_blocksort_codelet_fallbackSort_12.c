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
    UInt32 local_cc = cc;
    for (i = l; i <= r; i += 2) {
        Int32 idx1 = i;
        Int32 idx2 = i + 1;
        UInt32 val1 = eclass[fmap[idx1]];
        UInt32 val2 = (idx2 <= r) ? eclass[fmap[idx2]] : val1;

        if (local_cc != val1) {
            bhtab[idx1 >> 5] |= (1 << (idx1 & 31));
            local_cc = val1;
        }
        if (local_cc != val2 && idx2 <= r) {
            bhtab[idx2 >> 5] |= (1 << (idx2 & 31));
            local_cc = val2;
        }
    }
    cc = local_cc;
}
