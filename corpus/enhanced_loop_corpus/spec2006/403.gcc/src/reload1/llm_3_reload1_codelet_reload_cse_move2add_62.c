#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing
    int indices[53];
    for (int j = 0; j < 53; j++) {
        indices[j] = 53 - 1 - j;  // Reverse order indices: 52, 51, ..., 0
    }
    for (i = 0; i < 53; i++) {
        reg_set_luid[indices[i]] = 0;
    }
}
