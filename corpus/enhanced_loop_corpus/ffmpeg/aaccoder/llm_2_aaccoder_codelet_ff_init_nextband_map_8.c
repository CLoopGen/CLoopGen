#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // First initialize even indices, then handle odd indices in a second pass
    for (g = 0; g < 128; g += 2)
        nextband[g] = g;
    for (g = 1; g < 128; g += 2)
        nextband[g] = g;
}
