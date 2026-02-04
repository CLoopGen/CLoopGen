#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t scale;
extern int i;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // Loop runs for half the effective size to stay within bounds
    for (i = 0; i < 5; i += 2)
        energy[i] = (energy[i] << scale) >> 16;
}
