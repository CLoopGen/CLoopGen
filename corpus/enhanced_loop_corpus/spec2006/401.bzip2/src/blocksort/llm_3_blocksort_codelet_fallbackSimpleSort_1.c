#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *fmap;
extern UInt32 *eclass;
extern Int32 lo;
extern Int32 hi;
extern Int32 i;
extern Int32 j;
extern Int32 tmp;
extern UInt32 ec_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
UInt32 *fmap_base = &fmap[lo];
Int32 range = hi - lo;
for (i = range - 4; i >= 0; i--) {
    Int32 idx_i = i + lo;
    tmp = fmap_base[i];
    ec_tmp = eclass[tmp];
    for (j = i + 4; j <= range && ec_tmp > eclass[fmap_base[j]]; j += 4)
        fmap_base[j - 4] = fmap_base[j];
    fmap_base[j - 4] = tmp;
}
}
