#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with reversed iteration order (descending loop)
    for (i = 7; i >= 3; i--)
        offset[i] = 0;
}
