#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to simulate random-like access pattern
    uint8_t indices[15];
    for (int j = 0; j < 15; j++) {
        indices[j] = j + 1; // indices contain 1 to 15
    }
    // Reorder indices in reverse to create a deterministic but indirect access pattern
    for (i = 0; i < 15; i++) {
        s[indices[14 - i]] = s[0]; // Access s in reverse order: 15, 14, ..., 1
    }
}
