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
        prev_a = a;       // Create RAW: use of 'a' before update
        a >>= 1;          // Update 'a' based on its previous value (RAW dependency)
        if (l % 2 == 0) {
            a += prev_a >> 2; // Add artificial dependency: use prev_a (WAR-like usage)
        }
    }
}
