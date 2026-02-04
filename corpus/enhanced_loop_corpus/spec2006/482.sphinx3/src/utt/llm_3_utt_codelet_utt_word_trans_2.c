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
    int32 index = p * 2; // Strided access with stride 2
    if (index < n_ci) {
        bs[index] = ((int32)2147483648U);
        bv[index] = -1;
    }
}
}
