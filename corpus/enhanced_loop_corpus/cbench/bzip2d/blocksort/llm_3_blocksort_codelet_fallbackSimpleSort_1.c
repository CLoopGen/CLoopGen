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
for (i = hi; i >= lo; i--) {
    tmp = fmap[(i * 3) % (hi - lo + 1) + lo];  // Indirect access via strided index
    ec_tmp = eclass[tmp];
    for (j = i + 1; j <= hi && ec_tmp > eclass[fmap[(j * 3) % (hi - lo + 1) + lo]]; j++)
        fmap[(j * 3) % (hi - lo + 1) + lo - 1] = fmap[(j * 3) % (hi - lo + 1) + lo];
    fmap[(j * 3) % (hi - lo + 1) + lo - 1] = tmp;
}
}
