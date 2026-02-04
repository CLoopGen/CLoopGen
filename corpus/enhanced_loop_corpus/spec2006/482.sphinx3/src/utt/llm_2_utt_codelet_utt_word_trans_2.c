#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n_ci;
extern int32 *bs;
extern int32 *bv;
extern int32 p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = 0; p < n_ci; p += 2) {
    if (p + 1 < n_ci) {
        bs[p] = ((int32)2147483648U);
        bs[p + 1] = ((int32)2147483648U);
        bv[p] = -1;
        bv[p + 1] = -1;
    } else {
        bs[p] = ((int32)2147483648U);
        bv[p] = -1;
    }
}
}
