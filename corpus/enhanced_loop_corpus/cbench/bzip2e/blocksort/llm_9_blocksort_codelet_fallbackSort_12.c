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
    UInt32 shift_val, mask_val;
    for (i = l; i <= r; i++) {
        cc1 = eclass[fmap[i]];
        if (cc != cc1) {
            shift_val = i & 31;
            mask_val = (UInt32)1 << shift_val;
            bhtab[(i) >> 5] = bhtab[(i) >> 5] | mask_val;
            cc = cc1;
        }
    }
}
