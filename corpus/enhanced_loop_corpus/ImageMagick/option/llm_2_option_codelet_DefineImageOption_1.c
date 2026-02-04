#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (forward skipping)
    // This variant processes every second byte, simulating a strided access pattern.
    // It still searches for '=' but skips elements to demonstrate non-consecutive access.
    ptrdiff_t offset = 0;
    for (p = key; p[offset] != '\x00'; offset += 2) {
        if (p[offset] == '=') {
            p += offset;
            break;
        }
        // Prevent going out of bounds in case of odd-length sequences
        if (p[offset + 1] == '\x00') {
            p += offset;
            break;
        }
    }
    // Adjust final pointer position if not already set by break
    if (p[offset] == '\x00' && offset > 0)
        p += offset;
}
