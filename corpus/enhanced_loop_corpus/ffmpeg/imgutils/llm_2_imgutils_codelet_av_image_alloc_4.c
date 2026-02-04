#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, then fill in reverse order)
    for (i = 0; i < 4; i += 2)
        linesizes[i] = (((linesizes[i]) + (align) - 1) & ~((align) - 1));
    for (i = 3; i >= 0; i -= 2)
        linesizes[i] = (((linesizes[i]) + (align) - 1) & ~((align) - 1));
}
