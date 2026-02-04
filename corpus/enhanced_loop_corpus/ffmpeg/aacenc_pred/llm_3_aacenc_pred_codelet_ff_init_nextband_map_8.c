#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    uint8_t indices[128];
    for (int i = 0; i < 128; i++) {
        indices[i] = (uint8_t)(127 - i); // Reverse order access
    }
    for (g = 0; g < 128; g++) {
        nextband[indices[g]] = indices[g];
    }
}
