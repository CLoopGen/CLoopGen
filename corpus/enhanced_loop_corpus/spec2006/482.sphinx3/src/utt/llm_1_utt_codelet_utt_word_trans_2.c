#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n_ci;
extern int32 *bs;
extern int32 *bv;
extern int32 p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n_ci > 0) {
    for (int32 p = 0; p < n_ci; p += 2) {
        bs[p] = ((int32)2147483648U);
        bv[p] = -1;
        if (p + 1 < n_ci) {
            bs[p + 1] = ((int32)2147483648U);
            bv[p + 1] = -1;
        }
    }
}
}
