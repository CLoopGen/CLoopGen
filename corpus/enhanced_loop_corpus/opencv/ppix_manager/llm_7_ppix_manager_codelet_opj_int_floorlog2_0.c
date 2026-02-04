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
        a >>= 1; // Break direct loop-carried dependency on 'a' for condition
        prev_a = a; // Introduce RAW (read-after-write) dependency
    }
}
