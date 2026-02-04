#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern int i;
extern JLONG *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration but same write pattern
    JLONG *temp_ptr = bptr + ((1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3))) - 1;
    for (i = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1; i >= 0; i--) {
        *temp_ptr-- = 2147483647L;
    }
    bptr += (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)); // Update original pointer to reflect advance
}
