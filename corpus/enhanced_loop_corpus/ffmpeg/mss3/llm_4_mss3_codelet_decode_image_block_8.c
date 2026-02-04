#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 4; ++i) {
        vec[i] = 0;
        if (i == 2) i++; // Skip index 3 by mutating the loop variable
    }
}
