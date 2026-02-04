#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with larger stride and reverse traversal
    // Access every 4th element forward, then fill gaps in a second pass with offset
    for (i = 0; i < 64; i++) {
        ((data)[4 * i]) = 0.;
        ((data)[4 * i + 2]) = 0.;
    }
    for (i = 0; i < 64; i++) {
        ((data)[4 * i + 1]) = 0.;
        ((data)[4 * i + 3]) = 0.;
    }
}
