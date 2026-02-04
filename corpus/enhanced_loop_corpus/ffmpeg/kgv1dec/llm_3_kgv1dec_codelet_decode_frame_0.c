#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offsets[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Alters access pattern to go from high to low index
    for (i = 7; i >= 0; i--)
        offsets[i] = -1;
}
