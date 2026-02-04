#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 1 (simulating potential future striding)
    // Here we maintain logical equivalence but express the index explicitly
    for (v = 0; v < nGroups; v++) {
        int idx = v; // Direct but named indexing
        pos[idx] = v;
    }
}
