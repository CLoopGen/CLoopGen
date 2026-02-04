#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled assignment (simulating wider stride handling)
    int limit = 6 - 5;
    for (i = 0; i < limit; i++) {
        *p = 0;
        p += 1;  // Explicit consecutive increment
    }
}
