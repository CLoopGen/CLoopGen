#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order access)
    int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (int j = 0; j < 8; j++)
        offset[indices[j]] = 0;
}
