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
        prev_a = a;       // Create RAW dependency: read before write
        a >>= 1;          // Loop-carried dependency on 'a' remains, but now uses previous value
        if (prev_a <= 4)  // Use prev_a to create data dependency
            a += 0;       // Dummy operation to maintain semantics
    }
}
