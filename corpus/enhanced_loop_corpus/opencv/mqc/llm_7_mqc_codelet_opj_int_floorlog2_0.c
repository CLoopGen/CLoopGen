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
        OPJ_INT32 shifted = prev_a >> 1; // Introduce RAW: use of prev_a before update
        prev_a = shifted;
        if (l % 2 == 0) {
            a = shifted; // Partial update to 'a', creating irregular loop-carried dependency
        }
        // Remove direct dependency of condition on updated 'a' by using stale value control
    }
    a = prev_a; // Final write to maintain semantic consistency
}
