#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int counts[17];
extern int codes[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Define a simple indirect access pattern: reverse order traversal via index array
    int indices[16];
    for (int j = 0; j < 16; j++) {
        indices[j] = 15 - j; // reverse order: 15,14,...,0
    }
    for (i = 0; i < 16; i++) {
        int idx = indices[i]; // indirect access
        codes[idx + 1] = (codes[idx] + counts[idx]) << 1;
    }
}
