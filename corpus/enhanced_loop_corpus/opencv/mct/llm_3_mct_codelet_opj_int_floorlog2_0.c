#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[8];
    for (OPJ_INT32 i = 0; i < 8; i++) {
        arr[i] = a >> i;       // Precompute shifted values with consecutive storage
    }
    l = 0;
    for (OPJ_INT32 stride = 1; stride < 8 && a > 1; stride += 2, l++) { // Strided access pattern
        a = arr[stride];
        a >>= 1;
    }
}
