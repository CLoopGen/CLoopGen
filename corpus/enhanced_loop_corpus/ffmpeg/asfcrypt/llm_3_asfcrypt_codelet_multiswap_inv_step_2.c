#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward access starting from a higher offset
    v = 1; // reset v for consistent behavior
    for (i = 8; i >= 5; i--) { // Access keys[8], keys[7], keys[6], keys[5] consecutively
        v *= keys[i];
        v = (v >> 16) | (v << 16);
    }
}
