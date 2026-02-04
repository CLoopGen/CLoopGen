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
        prev_a = a;       // Add RAW: read before potential update
        a >>= 1;          // Original operation
        if (l % 2 == 0) {
            a += prev_a >> 2; // Introduce additional data dependency (RAW and WAR)
        }
    }
}
