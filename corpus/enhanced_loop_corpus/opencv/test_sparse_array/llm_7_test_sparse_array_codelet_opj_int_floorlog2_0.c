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
    for (l = 0; prev_a > 1; l++) {
        a = prev_a >> 1; // Introduce WAR: write to 'a' early, may affect outer scope
        prev_a >>= 1;    // Update local copy independently, breaking direct loop-carried RAW on 'a'
    }
    a = prev_a; // Final update to maintain some semantic consistency
}
