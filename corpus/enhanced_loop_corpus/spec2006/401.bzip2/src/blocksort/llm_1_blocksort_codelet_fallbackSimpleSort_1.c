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
    // Increase loop nesting depth by adding an outer control layer
    for (Int32 step = 4; step <= 4; step *= 2) {  // Artificial outer loop for depth
        for (i = hi - step; i >= lo; i--) {
            tmp = fmap[i];
            ec_tmp = eclass[tmp];
            for (j = i + step; j <= hi && ec_tmp > eclass[fmap[j]]; j += step)
                fmap[j - step] = fmap[j];
            fmap[j - step] = tmp;
        }
    }
}
