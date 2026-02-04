#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dc_in_use[16];
extern char ac_in_use[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index mapping (reverse order traversal)
    int indices[16];
    for (i = 0; i < 16; i++) {
        indices[i] = 15 - i; // reverse indexing
    }
    for (i = 0; i < 16; i++) {
        int j = indices[i];
        dc_in_use[j] = 0;
        ac_in_use[j] = 0;
    }
}
