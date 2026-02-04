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
    for (i = hi - 4; i >= lo; i--) {
        tmp = fmap[i];
        ec_tmp = eclass[tmp];
        for (j = i + 4; j <= hi && ec_tmp > eclass[fmap[j]]; j += 4) {
            fmap[j - 4] = fmap[j];
            // Additional inner loop to increase nesting depth
            for (Int32 k = 0; k < 2; k++) {
                if (j - 4 > lo + k) {
                    fmap[j - 4 - k] = fmap[j - k];
                }
            }
        }
        fmap[j - 4] = tmp;
    }
}
