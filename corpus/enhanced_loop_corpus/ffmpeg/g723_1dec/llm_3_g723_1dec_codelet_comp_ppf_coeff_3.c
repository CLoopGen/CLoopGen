#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp1;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = 4; i >= 0; i--)
        temp1 = (energy[i] > temp1) ? energy[i] : temp1;
}
