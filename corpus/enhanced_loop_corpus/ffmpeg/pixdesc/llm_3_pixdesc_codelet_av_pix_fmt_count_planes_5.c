#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int planes[4];
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulating gather pattern)
    int indices[] = {3, 1, 0, 2}; // Define a reordering of the array indices
    int n = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < n; i++)
        ret += planes[indices[i]];
}
