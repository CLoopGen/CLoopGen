#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with reordered computation
    // The source is now accessed consecutively from a computed base, improving spatial locality
    int base = 1663 - 255;
    for (i = 0; i < 256; i++) {
        float temp = window[base + i];  // Consecutive read
        window[2304 + i] = temp;      // Consecutive write
        window[1152 + i] = temp;      // Consecutive write
    }
}
