#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index mapping array (simulated via calculated indices)
    int indices[257];
    for (i = 0; i < 257; i++) {
        indices[i] = 256 - i; // Reverse access order: from last to first
    }
    for (i = 0; i < 257; i++) {
        others[indices[i]] = -1;
    }
}
