#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 prev_a = a;
    for (l = 0; a > 1; ++l) {
        prev_a = a;
        a >>= 1;
        if (prev_a <= a) break; // Introduce anti-dependence (WAR) and potential early exit
    }
}
