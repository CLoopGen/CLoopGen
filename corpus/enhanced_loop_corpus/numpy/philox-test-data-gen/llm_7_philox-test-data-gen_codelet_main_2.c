#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_array[2];
    for (i = 0; i < 2; i++) {
        temp_array[i] = i * i;
    }
    // Eliminates loop-carried dependencies by writing to distinct memory locations
    // Each iteration is independent — no RAW, WAR, or WAW dependencies between iterations
    // Enables potential vectorization and parallel execution.
}
