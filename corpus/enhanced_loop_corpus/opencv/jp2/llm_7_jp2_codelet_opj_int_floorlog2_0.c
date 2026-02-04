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
        prev_a = a;       // Capture previous value (introduces RAW dependency)
        a >>= 1;          // Current operation depends on prior 'a' (loop-carried RAW)
        if (prev_a <= 4) { // Use of prev_a creates additional data path
            break;
        }
    }
}
