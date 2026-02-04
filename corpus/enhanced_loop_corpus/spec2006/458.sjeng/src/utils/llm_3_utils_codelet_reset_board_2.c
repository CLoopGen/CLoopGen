#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int indices[144];
    for (i = 0; i < 144; i++) {
        indices[i] = 143 - i; // reverse order access
    }
    for (i = 0; i < 144; i++) {
        moved[indices[i]] = 0;
    }
}
