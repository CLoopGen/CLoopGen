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
        prev_a = a;       // RAW dependency: read before write
        a >>= 1;          // Use current value before modifying
        if (l % 2 == 0) {
            a += prev_a >> 2; // Introduce loop-carried dependency via prev_a
        }
    }
}
