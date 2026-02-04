#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element forward, then fill gaps)
    // We break the loop into two phases to maintain zero-initialization with stride
    for (int stride = 3; stride >= 0; stride--) {
        for (i = 65536 - stride; i >= 0; i -= 4) {
            if (i + stride <= 65536) {
                ftab[i + stride] = 0;
            }
        }
    }
}
