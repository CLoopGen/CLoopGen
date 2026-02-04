#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int indices[257];
    for (i = 0; i < 257; i++) {
        indices[i] = i; // Populate index map in order (could be randomized or reordered in real use cases)
    }
    for (i = 0; i < 257; i++) {
        others[indices[i]] = -1;
    }
}
