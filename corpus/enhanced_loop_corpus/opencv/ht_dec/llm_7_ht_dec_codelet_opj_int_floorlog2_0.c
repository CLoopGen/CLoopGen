#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 prev_a = a;
    for (l = 0; a > 1; l++) {
        OPJ_INT32 next_a = prev_a >> 1; // Introduce RAW dependency: read-before-write
        prev_a = a; // Create loop-carried dependency via prev_a
        a = next_a;
    }
}
