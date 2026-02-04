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
    bs[p] = ((int32)2147483648U);
    bv[p] = -1;
    if (p == n_ci / 2) {
        break;
    }
}
}
