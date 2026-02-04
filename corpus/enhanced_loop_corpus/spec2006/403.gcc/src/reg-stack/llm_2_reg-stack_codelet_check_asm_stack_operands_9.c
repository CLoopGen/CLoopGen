#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char implicitly_dies[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (; i < (8 + 7) + 1; i += 2)
        if (i < 53 && implicitly_dies[i])
            break;
}
