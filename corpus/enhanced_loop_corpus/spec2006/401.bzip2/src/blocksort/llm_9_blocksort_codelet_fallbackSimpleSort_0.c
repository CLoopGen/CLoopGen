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
Int32 stride = 2;
for (i = hi - (hi - lo + 1) % stride; i >= lo; i -= stride) {
    for (Int32 k = 0; k < stride && (i - k) >= lo; k++) {
        Int32 idx = i - k;
        tmp = fmap[idx];
        ec_tmp = eclass[tmp];
        for (j = idx + 1; j <= hi && ec_tmp > eclass[fmap[j]]; j++)
            fmap[j - 1] = fmap[j];
        fmap[j - 1] = tmp;
    }
}
}
