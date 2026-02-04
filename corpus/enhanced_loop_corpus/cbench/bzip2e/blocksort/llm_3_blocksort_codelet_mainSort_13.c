#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with pointer arithmetic
    // Changed direction from reverse to forward and use pointer instead of index
    UInt32 *base = ftab;
    for (i = 0; i <= 65536; i++) {
        *(base + i) = 0;
    }
}
