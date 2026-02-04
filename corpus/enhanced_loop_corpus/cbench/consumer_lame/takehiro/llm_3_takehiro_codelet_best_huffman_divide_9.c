#include <stdio.h>

#include <inttypes.h>

extern int r0;
extern int r3_bits[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset base index (simulate shifted window)
    int start = r0;
    int end = 7 + 15 + 2;
    for (int i = start; i <= end && i < 25; i++) {
        r3_bits[i] = 100000;
    }
    r0 = end + 1; // Maintain logical update of r0 as in original
}
