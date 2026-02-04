#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to start
    for (i = nc - 1; i >= 0; i--)
        nmem[i] = 0;
}
