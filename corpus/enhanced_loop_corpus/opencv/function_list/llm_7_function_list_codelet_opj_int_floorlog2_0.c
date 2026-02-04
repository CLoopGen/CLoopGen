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
        prev_a = a;       // RAW: use current 'a' before update
        a >>= 1;          // WAR: write 'a' after reading in prev_a
        if ((prev_a & 1) && l < 5) { // Introduce conditional data dependency
            a += l;       // Additional WAW on 'a', creating loop-carried dependency
        }
    }
}
