#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[64];
    OPJ_INT32 stride = 2;
    OPJ_INT32 pos = 0;
    for (l = 0; a > 1; l++) {
        arr[pos * stride] = a;  // Strided memory access pattern
        a >>= 1;
        pos++;
    }
    // Dummy use to prevent elimination
    if (pos > 0) a = arr[0];
}
