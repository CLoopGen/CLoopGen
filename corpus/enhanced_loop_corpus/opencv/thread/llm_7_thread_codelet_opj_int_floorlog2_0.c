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
        prev_a = a;       // Break potential RAW by caching old value
        a >>= 1;          // Original operation
        if (l % 2 == 0) { // Introduce conditional update to break uniformity
            a += (prev_a & 1); // Add dependency on previous value (RAW)
        }
    }
}
