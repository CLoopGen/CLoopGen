#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t scale;
extern int i;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Iterates from last to first element
    for (i = 4; i >= 0; i--)
        energy[i] = (energy[i] << scale) >> 16;
}
