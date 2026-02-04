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
for (i = (hi - 1) / stride * stride; i >= lo; i -= stride) {
    Int32 idx_i = i;
    tmp = fmap[idx_i];
    ec_tmp = eclass[tmp];
    for (j = i + stride; j <= hi && j < lo + ((hi - lo + 1) / stride) * stride && ec_tmp > eclass[fmap[j]]; j += stride) {
        Int32 idx_j_minus_1 = j - stride;
        Int32 idx_j = j;
        fmap[idx_j_minus_1] = fmap[idx_j];
    }
    fmap[j - stride] = tmp;
}
}
