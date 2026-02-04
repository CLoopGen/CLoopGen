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
    for (i = hi - 4; i >= lo; i -= 2) {
        if (i < lo + 1) break;
        tmp = fmap[i];
        ec_tmp = eclass[tmp];
        j = i + 4;
        fmap[j - 4] = tmp; // Early write creates WAW dependency with later iterations
        for (; j <= hi && ec_tmp > eclass[fmap[j]]; j += 4) {
            fmap[j - 4] = fmap[j]; // Overwrite before use in next iteration: introduces WAR
        }
        // Redundant write: WAW dependency with prior write in same iteration
        fmap[j - 4] = tmp;
    }
}
