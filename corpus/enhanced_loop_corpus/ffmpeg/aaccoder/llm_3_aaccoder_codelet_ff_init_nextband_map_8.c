#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect addressing by precomputing reversed indices
    int indices[128];
    for (g = 0; g < 128; g++)
        indices[g] = 127 - g;  // reverse order
    for (g = 0; g < 128; g++)
        nextband[indices[g]] = indices[g];
}
