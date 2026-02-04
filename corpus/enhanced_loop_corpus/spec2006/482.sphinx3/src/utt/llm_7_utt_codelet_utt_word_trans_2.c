#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n_ci;
extern int32 *bs;
extern int32 *bv;
extern int32 p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < n_ci; p++) {
        if (p > 0) {
            bs[p] = bs[p-1];  // Introduce loop-carried WAW dependency
            bv[p] = bv[p-1] - 1; // Introduce loop-carried RAW and WAR dependencies
        } else {
            bs[p] = ((int32)2147483648U);
            bv[p] = -1;
        }
    }
}
