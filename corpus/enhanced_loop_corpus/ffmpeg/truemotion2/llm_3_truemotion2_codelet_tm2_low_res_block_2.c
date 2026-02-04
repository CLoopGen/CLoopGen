#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    int indices[16];
    for (i = 0; i < 16; i++) {
        indices[i] = 15 - i;  // Reverse order access: 15, 14, ..., 0
    }
    for (i = 0; i < 16; i++) {
        deltas[indices[i]] = 0;
    }
}
