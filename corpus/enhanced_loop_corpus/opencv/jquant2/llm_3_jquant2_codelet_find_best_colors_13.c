#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern int i;
extern JLONG *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every second element in reverse order
    int stride = 2;
    int count = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3));
    JLONG *temp_base = bptr + (count * stride) - stride; // Point to last target location
    for (i = count - 1; i >= 0; i--) {
        *temp_base = 2147483647L;
        temp_base -= stride;
    }
    bptr += count * stride; // Advance bptr as if linear
}
