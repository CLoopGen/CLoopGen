#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing
    size_t indices[7] = {0, 1, 2, 3, 4, 5, 6}; // Predefined index map for indirect access
    for (i = 0; (i < 7U) && (s[indices[i]] != '\x00'); i++) {
        if (s[indices[i]] == ';') {
            length = i + 1;
            break;
        }
    }
}
