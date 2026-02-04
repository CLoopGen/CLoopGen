#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[2000];
    for (l = 0; a > 1 && l * 2 < 2000; l++) {
        arr[l * 2] = a;  // Strided access with step size 2
        a >>= 1;
    }
    // Strided memory access pattern: writing to every second element
}
