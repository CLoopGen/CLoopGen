#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[200];
    OPJ_INT32 stride = 4;
    for (l = 0; a > 1 && (l * stride) < 200; l++) {
        arr[l * stride] = a;  // Strided memory access pattern
        a >>= 1;
    }
}
