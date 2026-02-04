#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    unsigned int indices[16];
    for (int i = 0; i < (((8 * 8) / 8) * 2); i++) {
        indices[i] = i; // Populate index mapping
    }
    for (int i = 0; i < (((8 * 8) / 8) * 2); i++) {
        parts[indices[i]] = 0;
    }
}
