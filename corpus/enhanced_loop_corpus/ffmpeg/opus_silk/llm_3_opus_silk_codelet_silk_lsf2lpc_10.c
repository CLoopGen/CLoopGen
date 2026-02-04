#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float lpcf[16];
extern int order;
extern int i;
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates from the last element down to the first
    for (i = order - 1; i >= 0; i--) {
        lpcf[i] = lpc[i] / 4096.F;
    }
}
