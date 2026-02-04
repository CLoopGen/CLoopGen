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
Int32 range = hi - lo + 1;
for (i = range - 1; i >= 0; i--) {
    tmp = fmap_base[i];
    ec_tmp = eclass[tmp];
    for (j = i + 1; j < range && ec_tmp > eclass[fmap_base[j]]; j++)
        fmap_base[j - 1] = fmap_base[j];
    fmap_base[j - 1] = tmp;
}
}
