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
for (i = hi - 8; i >= lo; i -= 2) {
    tmp = fmap[i];
    ec_tmp = eclass[tmp];
    for (j = i + 8; j <= hi && ec_tmp > eclass[fmap[j]]; j += 8)
        fmap[j - 8] = fmap[j];
    fmap[j - 8] = tmp;
}
}
