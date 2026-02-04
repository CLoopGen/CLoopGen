#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *base;
extern UChar *length;
extern Int32 alphaSize;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolled-like pattern)
    // Access every second element in a forward pass, then handle remainder
    for (i = 0; i < alphaSize; i += 2) {
        if (i < alphaSize) {
            base[length[i] + 1]++;
        }
        if (i + 1 < alphaSize) {
            base[length[i + 1] + 1]++;
        }
    }
}
