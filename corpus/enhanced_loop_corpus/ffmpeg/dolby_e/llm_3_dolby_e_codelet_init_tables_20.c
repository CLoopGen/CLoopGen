#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write using pointer arithmetic for improved locality
    float *base = &window[1088];
    for (i = 0; i < 64; i++) {
        *(base + i) = 1.F;
    }
}
