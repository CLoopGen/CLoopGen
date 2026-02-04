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
        prev_a = a;       // Break direct loop-carried RAW by using previous value
        a >>= 1;          // Original shift
        if (l % 2 == 0) { // Introduce conditional update to eliminate consistent loop-carried dependency
            a += (prev_a & 1); // Use prior state, creating intra-iteration dependency
        }
    }
}
