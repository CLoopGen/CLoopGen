#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element forward, then clean up remainder)
    // Using a positive stride and unrolling to touch elements in strided pattern
    for (i = 0; i <= 65536; i += 4) {
        ftab[i] = 0;
    }
    for (i = 1; i <= 65536; i += 4) {
        ftab[i] = 0;
    }
    for (i = 2; i <= 65536; i += 4) {
        ftab[i] = 0;
    }
    for (i = 3; i <= 65536; i += 4) {
        ftab[i] = 0;
    }
}
