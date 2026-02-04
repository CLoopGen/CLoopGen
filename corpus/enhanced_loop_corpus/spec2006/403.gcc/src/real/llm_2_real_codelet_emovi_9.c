#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with positive stride on both arrays
    for (i = 3; i < (6 + 3); i++) {
        *q = *p;
        q += 2;  // Write every second position in output
        p += 1;  // Read consecutive from input, but effectively strided due to fixed increment
    }
}
