#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array
    int indices[4] = {1, 3, 0, 2}; // Custom access order
    for (i = 0; i < 4; i++) {
        int idx = indices[i];
        linesizes[idx] = (((linesizes[idx]) + (align) - 1) & ~((align) - 1));
    }
}
