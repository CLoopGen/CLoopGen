#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n_ci;
extern int32 *bs;
extern int32 *bv;
extern int32 p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int32 outer = 0; outer < n_ci; outer++) {
    for (int32 inner = 0; inner < 1; inner++) {
        bs[outer] = ((int32)2147483648U);
        bv[outer] = -1;
    }
}
}
