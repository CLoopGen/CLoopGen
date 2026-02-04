#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int cmap[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    int indices[4] = {3, 1, 0, 2}; // Reordered indices
    for (i = 0; i < 4; i++)
        cmap[indices[i]] = i;
}
