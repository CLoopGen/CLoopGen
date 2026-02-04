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
        prev_a = a;       // Add RAW dependency: read 'a' before next write
        a >>= 1;          // Original operation, now with explicit use of previous value
        if (prev_a <= 4)  // Introduce loop-carried dependency via control flow
            a += 0;       // Preserve semantics but create data-path link across iterations
    }
}
