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
    Int32 local_tmp;
    UInt32 local_ec_tmp;
    for (i = hi - 4; i >= lo; i--) {
        local_tmp = fmap[i];
        local_ec_tmp = eclass[local_tmp];
        for (j = i + 4; j <= hi; j += 4) {
            if (!(local_ec_tmp > eclass[fmap[j]])) break;
            // Eliminate loop-carried dependence by unrolling two steps ahead
            if (j + 4 <= hi && local_ec_tmp > eclass[fmap[j + 4]]) {
                fmap[j - 4] = fmap[j + 4]; // Skip one element, reducing dependency chain
                j += 4;
            } else {
                fmap[j - 4] = fmap[j];
            }
        }
        fmap[j - 4] = local_tmp;
    }
}
