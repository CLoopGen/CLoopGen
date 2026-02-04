#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect addressing by using a fixed offset lookup table
    int indices[4] = {3, 2, 1, 0}; // Reverse order access: little-endian like reversal
    for (i = 0; i < 4; i++)
        p[indices[i]] = (uint8_t)(w >> (8 * i));
}
