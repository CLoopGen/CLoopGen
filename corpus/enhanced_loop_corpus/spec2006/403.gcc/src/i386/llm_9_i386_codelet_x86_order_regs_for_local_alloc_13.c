#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with fewer iterations and simplified addressing
    int step = 2;
    for (i = (20 + 1); i <= ((20 + 1) + 6); i += step)  // Trip count reduced to 4 iterations, stride of 2
        reg_alloc_order[pos++] = i;
}
