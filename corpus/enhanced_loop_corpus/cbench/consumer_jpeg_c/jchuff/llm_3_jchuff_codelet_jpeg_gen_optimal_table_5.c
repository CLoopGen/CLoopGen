#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index map (simulated with simple transformation)
    int indices[257];
    for (i = 0; i < 257; i++) {
        indices[i] = i; // Identity mapping for simplicity, could be randomized or reordered in practice
    }
    for (i = 0; i < 257; i++) {
        others[indices[i]] = -1;
    }
}
