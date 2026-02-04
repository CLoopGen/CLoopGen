#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), iterating backwards in steps
    for (i = 254; i >= 0; i -= 2) {
        if (aslide[i] || bslide[i]) {
            break;
        }
        // Check the next element in stride if within bounds
        if (i > 0 && (aslide[i-1] || bslide[i-1])) {
            i--; // Adjust index to reflect actual position found
            break;
        }
    }
    // Final check for index 0 if loop ended without breaking
    if (i < 0) {
        if (aslide[0] || bslide[0]) i = 0;
        else i = -1;
    }
}
