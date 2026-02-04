#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize_align[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[4] = {3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 4; i++)
        linesize_align[indices[i]] = 8;
}
