#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < m; i++) {
        j = i * 2;
        // No loop-carried dependencies: each iteration writes to `j` independently and does not use prior values.
        // Eliminates any RAW, WAR, or WAW dependencies across iterations, enabling full parallelization potential.
    }
}
