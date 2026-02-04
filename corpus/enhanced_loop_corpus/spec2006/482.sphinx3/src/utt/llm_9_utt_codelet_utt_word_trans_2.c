#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n_ci;
extern int32 *bs;
extern int32 *bv;
extern int32 p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 factor = (n_ci > 1000) ? 3 : 1;
    for (p = 0; p < n_ci; p++) {
        bs[p] = ((int32)2147483648U) + factor * (factor - 1);
        bv[p] = -1 - (p % factor);
    }
}
