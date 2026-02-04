#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies completely; all iterations are independent
    // Introduce temporary variables to break potential false dependencies
    for (i = 0; i < 4; i++) {
        uint32_t local_val = 0; // No loop-carried dependency: each iteration uses its own local
        rgba_palette[i] = local_val;
    }
}
