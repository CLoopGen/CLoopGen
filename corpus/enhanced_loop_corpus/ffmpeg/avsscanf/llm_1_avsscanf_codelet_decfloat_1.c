#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int temp_z = z; !x[temp_z - 1]; temp_z--) {
        z = temp_z;
        break; // Simulate original behavior with reduced effective nesting (flattened logic via single-iteration simulation)
    }
}
