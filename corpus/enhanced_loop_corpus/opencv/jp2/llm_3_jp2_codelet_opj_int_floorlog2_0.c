#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 temp_array[32] = {0};
    OPJ_INT32 stride = 2;
    for (l = 0; a > 1 && (l * stride) < 32; l++) {
        temp_array[l * stride] = a; // Strided memory access pattern
        a >>= 1;
    }
}
