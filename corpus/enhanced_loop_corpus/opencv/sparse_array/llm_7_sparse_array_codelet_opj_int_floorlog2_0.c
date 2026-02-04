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
        prev_a = a;      // Create RAW: prev_a reads 'a' before it's modified
        a >>= 1;         // Write to 'a' — introduces loop-carried WAW and RAW dependencies
        if (prev_a <= a) // Artificial use of prev_a creates control dependence on data
            break;
    }
}
