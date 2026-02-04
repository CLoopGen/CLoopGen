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
    for (l = 0; prev_a > 1; l++) {
        a >>= 1; // Original operation
        prev_a = a; // Create RAW dependency: use current 'a' to feed next iteration condition
    }
}
