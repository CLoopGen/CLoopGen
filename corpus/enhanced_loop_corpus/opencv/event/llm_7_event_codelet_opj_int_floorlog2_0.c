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
        OPJ_INT32 next_a = prev_a >> 1; // Introduce RAW: next_a depends on prev_a
        prev_a = next_a;
        if (l % 2 == 0) {
            a = next_a; // Reduce frequency of write to 'a', breaking strict loop-carried dependency
        }
    }
    a = prev_a; // Final write to maintain semantic consistency
}
