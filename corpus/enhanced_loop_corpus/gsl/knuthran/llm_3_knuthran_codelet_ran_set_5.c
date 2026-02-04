#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access in reverse order (from high to low index)
    for (; j >= 0 && j < 199; j++)
        x[198 - j] = 0;
}
