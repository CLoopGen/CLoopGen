#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

extern TIFFRGBValue *clamptab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Simulate indirect access by reversing the order of indices
    for (i = 0; i < 256; i++) {
        int idx = 255 - i;  // Access from end to start
        clamptab[idx] = 255 - idx;
    }
}
